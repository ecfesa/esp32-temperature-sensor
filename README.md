# ESP32 Temperature Monitor with MQTT

This project uses an ESP32 to monitor temperature via an analog input and sends the temperature data to a remote server using MQTT. The project also includes a Wi-Fi configuration portal using the ESP32's built-in capabilities, allowing easy setup and management of Wi-Fi credentials.

## Features

- Monitor temperature using an analog temperature sensor.
- Send temperature data to an MQTT broker.
- Configure Wi-Fi credentials via a captive portal.
- Reconnect to Wi-Fi and MQTT broker automatically if the connection is lost.

## Components

- ESP32 Development Board
- Temperature Simulator (Learning Kit)
- Fiware with MQTT Broker

## Installation

1. **Install Required Libraries:**

   Make sure you have the following libraries installed in your Arduino IDE:
   - `WiFiManager` by tzapu
   - `PubSubClient` by Nick O'Leary

   You can install these libraries using the Arduino Library Manager (`Sketch` > `Include Library` > `Manage Libraries...`).

## File Descriptions

- `main.ino`
  - Contains the setup and main loop of the program. Initializes Wi-Fi and MQTT, and handles the temperature monitoring loop.

- `WiFiManagerWrapper.h`
  - Declares functions for initializing and checking the Wi-Fi connection.

- `WiFiManagerWrapper.cpp`
  - Implements functions for managing the Wi-Fi connection using the `WiFiManager` library. Sets up a captive portal for configuring Wi-Fi credentials.

- `MQTTHandler.h`
  - Declares functions and variables for initializing and checking the MQTT connection.

- `MQTTHandler.cpp`
  - Implements functions for managing the MQTT connection using the `PubSubClient` library. Handles connecting and reconnecting to the MQTT broker.

- `TemperatureSensor.h`
  - Declares functions for reading the temperature from the sensor and publishing the data to the MQTT broker.

- `TemperatureSensor.cpp`
  - Implements functions for reading the temperature from the analog sensor, converting the reading to a temperature value, and publishing it to the MQTT broker.

## Usage

1. **Upload the Code:**

   Connect your ESP32 to your computer and upload the `main.cpp` using the Arduino IDE.

2. **Configure Wi-Fi:**

   - When the ESP32 starts, it will create a Wi-Fi access point named `AutoConnectAP`.
   - Connect to this access point using your phone or computer.
   - A captive portal should open automatically. If not, navigate to `192.168.4.1` in your web browser.
   - Enter your Wi-Fi credentials and connect.

3. **Monitor Temperature:**

   The ESP32 will read the temperature from the analog sensor and publish the data to the specified MQTT topic. You can monitor the serial output for debugging information.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [WiFiManager](https://github.com/tzapu/WiFiManager) by tzapu
- [PubSubClient](https://github.com/knolleary/pubsubclient) by Nick O'Leary
