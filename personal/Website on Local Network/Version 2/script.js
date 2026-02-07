async function fetchDevices() {
    const res = await fetch("/api/devices");
    const devices = await res.json();
    const container = document.getElementById("devices-list");
    container.innerHTML = "";
    devices.forEach(d => {
        const div = document.createElement("div");
        div.className = "device-card";
        div.innerHTML = `<span class="device-name">${d.name}</span>
                         <span class="badge ${d.online ? 'online':'offline'}">${d.online ? 'Online':'Offline'}</span>`;
        container.appendChild(div);
    });
}

async function fetchSensors() {
    const res = await fetch("/api/sensors");
    const data = await res.json();
    const container = document.getElementById("sensors-list");
    container.innerHTML = "";
    const div = document.createElement("div");
    div.className = "sensor-card";
    div.innerHTML = `Temp: ${data.bme280.temperature || 'N/A'}°C<br>
                     Humidity: ${data.bme280.humidity || 'N/A'}%<br>
                     Pressure: ${data.bme280.pressure || 'N/A'} hPa<br>
                     Light: ${data.ldr.raw_count || 'N/A'}`;
    container.appendChild(div);
}

async function fetchWeather() {
    const res = await fetch("/api/weather/all");
    const data = await res.json();
    const container = document.getElementById("weather-container");
    container.innerHTML = "";
    for (const loc in data) {
        const div = document.createElement("div");
        div.className = "weather-card";
        if(data[loc].error){
            div.innerHTML = `<span class="weather-location">${loc}</span><br><small>${data[loc].error}</small>`;
        } else {
            div.innerHTML = `<span class="weather-location">${loc}</span><br>
                             ${data[loc].main.temp}°C, ${data[loc].weather[0].description}`;
        }
        container.appendChild(div);
    }
}

async function addDevice() {
    const name = document.getElementById("device-name").value;
    const ip = document.getElementById("device-ip").value;
    if(!name || !ip) return;
    await fetch("/api/devices/add", {
        method: "POST",
        headers: {'Content-Type':'application/json'},
        body: JSON.stringify({name, ip})
    });
    document.getElementById("device-name").value = "";
    document.getElementById("device-ip").value = "";
    fetchDevices();
}

setInterval(() => { fetchDevices(); fetchSensors(); fetchWeather(); }, 5000);
window.onload = () => { fetchDevices(); fetchSensors(); fetchWeather(); };
