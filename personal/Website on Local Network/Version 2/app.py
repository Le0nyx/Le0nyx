import os, json, threading, time, subprocess
from flask import Flask, render_template, jsonify, request
import requests
from sensors import read_bme280, read_ldr, cleanup

app = Flask(__name__, template_folder="templates", static_folder="static")

# Config via environment variables
DEVICE_FILE = os.environ.get("DEVICE_FILE", "devices.json")
WEATHER_API_KEY = os.environ.get("WEATHER_API_KEY", "")
WEATHER_LOCATIONS = os.environ.get("WEATHER_LOCATIONS", "Rome,IT;London,UK").split(";")

# Globals
devices_status = {}
SENSOR_HISTORY = {"temperature": [], "humidity": [], "pressure": [], "light": []}
DEVICE_HISTORY = {}
MAX_HISTORY = 100

# Ping devices loop
def ping_devices():
    while True:
        try:
            if os.path.exists(DEVICE_FILE):
                with open(DEVICE_FILE, "r") as f:
                    devices = json.load(f)
                for d in devices:
                    ip = d.get("ip")
                    if not ip: continue
                    try:
                        result = subprocess.run(["ping", "-c", "1", "-W", "1", ip],
                                                stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
                        devices_status[ip] = (result.returncode == 0)
                    except:
                        devices_status[ip] = False
            time.sleep(5)
        except Exception as e:
            print("Ping thread error:", e)
            time.sleep(5)

# Sensor history loop
def update_sensor_history():
    while True:
        bme = read_bme280()
        ldr = read_ldr()
        if isinstance(bme, dict) and "error" not in bme:
            SENSOR_HISTORY["temperature"].append(bme["temperature"])
            SENSOR_HISTORY["humidity"].append(bme["humidity"])
            SENSOR_HISTORY["pressure"].append(bme["pressure"])
            SENSOR_HISTORY["light"].append(ldr.get("raw_count", 0))
            for k in SENSOR_HISTORY:
                if len(SENSOR_HISTORY[k]) > MAX_HISTORY:
                    SENSOR_HISTORY[k] = SENSOR_HISTORY[k][-MAX_HISTORY:]
        time.sleep(5)

# Device history loop
def update_device_history():
    while True:
        try:
            if os.path.exists(DEVICE_FILE):
                with open(DEVICE_FILE, "r") as f:
                    devices = json.load(f)
                for d in devices:
                    ip = d.get("ip")
                    if not ip: continue
                    status = 1 if devices_status.get(ip, False) else 0
                    if ip not in DEVICE_HISTORY:
                        DEVICE_HISTORY[ip] = []
                    DEVICE_HISTORY[ip].append(status)
                    if len(DEVICE_HISTORY[ip]) > MAX_HISTORY:
                        DEVICE_HISTORY[ip] = DEVICE_HISTORY[ip][-MAX_HISTORY:]
            time.sleep(5)
        except Exception as e:
            print("Device history thread error:", e)
            time.sleep(5)

# Start background threads
threading.Thread(target=ping_devices, daemon=True).start()
threading.Thread(target=update_sensor_history, daemon=True).start()
threading.Thread(target=update_device_history, daemon=True).start()

# Routes
@app.route("/")
def index():
    return render_template("index.html")

@app.route("/api/sensors")
def sensors():
    return jsonify({"bme280": read_bme280(), "ldr": read_ldr()})

@app.route("/api/sensors/history")
def sensors_history():
    return jsonify(SENSOR_HISTORY)

@app.route("/api/devices")
def devices():
    try:
        with open(DEVICE_FILE, "r") as f:
            devices = json.load(f)
        for d in devices:
            d["online"] = devices_status.get(d["ip"], False)
        return jsonify(devices)
    except:
        return jsonify([])

@app.route("/api/devices/history")
def devices_history():
    return jsonify(DEVICE_HISTORY)

@app.route("/api/devices/add", methods=["POST"])
def add_device():
    data = request.json
    if "name" in data and "ip" in data:
        devices = []
        if os.path.exists(DEVICE_FILE):
            with open(DEVICE_FILE, "r") as f:
                devices = json.load(f)
        devices.append({"name": data["name"], "ip": data["ip"]})
        with open(DEVICE_FILE, "w") as f:
            json.dump(devices, f, indent=2)
        return jsonify({"status": "ok"})
    return jsonify({"status": "error"}), 400

@app.route("/api/devices/delete", methods=["POST"])
def delete_device():
    data = request.json
    ip = data.get("ip")
    if ip and os.path.exists(DEVICE_FILE):
        with open(DEVICE_FILE, "r") as f:
            devices = json.load(f)
        devices = [d for d in devices if d.get("ip") != ip]
        with open(DEVICE_FILE, "w") as f:
            json.dump(devices, f, indent=2)
        return jsonify({"status": "ok"})
    return jsonify({"status": "error"}), 400

@app.route("/api/weather/all")
def weather_all():
    result = {}
    if not WEATHER_API_KEY:
        for loc in WEATHER_LOCATIONS:
            result[loc] = {"error": "No API Key set"}
        return jsonify(result)

    for loc in WEATHER_LOCATIONS:
        try:
            url = f"http://api.openweathermap.org/data/2.5/weather?q={loc}&appid={WEATHER_API_KEY}&units=metric"
            r = requests.get(url, timeout=6)
            r.raise_for_status()
            result[loc] = r.json()
        except Exception as e:
            result[loc] = {"error": str(e)}
    return jsonify(result)

if __name__ == "__main__":
    try:
        app.run(host="0.0.0.0", port=3003)
    finally:
        cleanup()
