Pi Dashboard Setup and Usage

Overview



This guide explains how to set up a Raspberry Pi dashboard that monitors devices, sensors, and weather data. It covers environment setup, running the dashboard, and optional systemd service configuration.



1\. Prerequisites



Ensure you have the following installed on your Raspberry Pi:



Python 3.11+

pip

Flask (pip install flask)

requests (pip install requests)

RPi.GPIO (pip install RPi.GPIO)

adafruit-circuitpython-bme280 (pip install adafruit-circuitpython-bme280)





Access to your local network devices to monitor

Optional: a virtual environment is recommended:



python -m venv venv

source venv/bin/activate

pip install flask requests RPi.GPIO adafruit-circuitpython-bme280



2\. Folder Structure



Create the following folder structure for the dashboard:



pi\_dashboard/

├── app.py

├── sensors.py

├── devices.json          # empty list: \[]

├── templates/

│   └── index.html

├── static/

│   ├── style.css

│   └── script.js





app.py – Main Flask application



sensors.py – Sensor reading code



devices.json – Stores device list



templates/index.html – Main HTML page



static/ – CSS and JS files



3\. Environment Variables



The application uses environment variables for sensitive or configurable data:



export WEATHER\_API\_KEY="your\_openweathermap\_api\_key"

export WEATHER\_LOCATIONS="Rome,IT;London,UK;"

export DEVICE\_FILE="/home/pi/pi\_dashboard/devices.json"  # optional, default is devices.json in app folder





WEATHER\_API\_KEY – OpenWeatherMap API key



WEATHER\_LOCATIONS – Semicolon-separated list of locations to display weather



DEVICE\_FILE – Optional custom path for devices.json



For temporary usage, export variables in the same terminal before running the app.

For permanent usage, add them to your ~/.bashrc or /etc/environment.



4\. Running the Dashboard



Activate your virtual environment (if using):



source venv/bin/activate





Run the Flask app:



python app.py





Open a browser and navigate to:



http://<raspberry\_pi\_ip>:3003





The dashboard will display:



Devices online/offline status



Sensor readings (temperature, humidity, pressure, light)



Weather data for configured locations



5\. Systemd Service (Optional)



To run the dashboard automatically on boot:



Create a service file /etc/systemd/system/pi\_dashboard.service:



\[Unit]

Description=Pi Dashboard

After=network.target



\[Service]

WorkingDirectory=/home/pi/pi\_dashboard

ExecStart=/home/pi/pi\_dashboard/venv/bin/python /home/pi/pi\_dashboard/app.py

User=pi

Restart=always



\[Install]

WantedBy=multi-user.target





Enable and start the service:



sudo systemctl daemon-reload

sudo systemctl enable pi\_dashboard.service

sudo systemctl start pi\_dashboard.service





Check status:



sudo systemctl status pi\_dashboard.service



6\. Adding Devices



Devices can be added via the web UI under the Devices section.

Alternatively, edit devices.json manually:



\[

&nbsp; { "name": "PC", "ip": "192.168.1.2" },

&nbsp; { "name": "Router", "ip": "192.168.1.1" }

]



7\. Notes



Sensor readings and device ping checks update every 5 seconds.

Weather data updates every 5 seconds for all configured locations.

Use the browser developer console to debug network errors if data fails to load.

Ensure your Pi and devices are on the same network for ping detection to work.

