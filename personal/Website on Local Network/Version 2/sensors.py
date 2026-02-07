import time
import RPi.GPIO as GPIO
import board
import adafruit_bme280

# BME280 I2C using Adafruit CircuitPython
i2c = board.I2C()
bme280 = adafruit_bme280.Adafruit_BME280_I2C(i2c, address=0x76)

# LDR RC timing on BCM pin 18
LDR_PIN = 18
GPIO.setmode(GPIO.BCM)

def read_bme280():
    try:
        return {
            "temperature": round(float(bme280.temperature), 1),
            "humidity": round(float(bme280.humidity), 1),
            "pressure": round(float(bme280.pressure), 1)
        }
    except Exception as e:
        return {"error": str(e)}

def read_ldr(cycles=5):
    vals = []
    for _ in range(cycles):
        GPIO.setup(LDR_PIN, GPIO.OUT)
        GPIO.output(LDR_PIN, False)  # discharge capacitor
        time.sleep(0.1)
        GPIO.setup(LDR_PIN, GPIO.IN)
        count = 0
        while GPIO.input(LDR_PIN) == GPIO.LOW:
            count += 1
            if count > 100000:
                break
        vals.append(count)
        time.sleep(0.05)
    avg = sum(vals)/len(vals) if vals else 0
    return {"raw_count": avg}

def cleanup():
    try:
        GPIO.cleanup()
    except Exception:
        pass
