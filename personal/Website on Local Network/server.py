import os
import time
import psutil
from flask import Flask, jsonify, request, send_from_directory

app = Flask(__name__)
UPLOAD_FOLDER = 'uploads'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

def get_stats():
    # Uptime
    boot_time = psutil.boot_time()
    current_time = time.time()
    uptime = current_time - boot_time

    # CPU 
    cpu_usage = psutil.cpu_percent(interval=1)

    # Memory 
    memory = psutil.virtual_memory()
    memory_info = f"{memory.percent}% used ({memory.used / (1024**3):.2f} GB of {memory.total / (1024**3):.2f} GB)"

    # Disk 
    disk = psutil.disk_usage('/')
    disk_usage = f"{disk.percent}% used ({disk.used / (1024**3):.2f} GB of {disk.total / (1024**3):.2f} GB)"

    # Network 
    net_io = psutil.net_io_counters()
    network_usage = f"Sent: {net_io.bytes_sent / (1024**2):.2f} MB | Recvd: {net_io.bytes_recv / (1024**2):.2f} MB"

    return {
        "uptime": f"{int(uptime // 3600)}h {int((uptime % 3600) // 60)}m",
        "cpu_usage": cpu_usage,
        "memory": memory_info,
        "disk_usage": disk_usage,
        "network_usage": network_usage
    }

@app.route('/stats', methods=['GET'])
def stats():
    return jsonify(get_stats())

# File upload to hosting pc into a folder
@app.route('/upload', methods=['POST'])
def upload():
    if 'file' not in request.files:
        return "No file part", 400
    file = request.files['file']
    if file.filename == '':
        return "No selected file", 400
    filepath = os.path.join(UPLOAD_FOLDER, file.filename)
    file.save(filepath)
    return f"File {file.filename} uploaded successfully!"

# route HTML and CSS
@app.route('/', methods=['GET'])
def index():
    return send_from_directory('.', 'index.html')

@app.route('/styles.css', methods=['GET'])
def styles():
    return send_from_directory('.', 'styles.css')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8000) # ip hidden for security reasons

