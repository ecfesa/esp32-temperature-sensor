#include <Arduino.h>
#include "MQTTHandler.h"

const int temp_sensor_pin = 25; // Temperature sensor analog pin
const char* topic_publish = "/TEF/temp008/attrs"; // MQTT topic to publish temperature data

/**
 * Reads the temperature from the analog sensor and publishes the data to the MQTT broker.
 * Converts the analog sensor value to a voltage, then to a temperature in degrees Celsius.
 */
void handleTemperature() {
    int sensorValue = analogRead(temp_sensor_pin);
    float voltage = sensorValue * (3.3 / 4095.0);
    float temperature = (voltage - 0.5) * 100.0;
    String temperatureStr = String(temperature);
    Serial.print("Temperature value: ");
    Serial.println(temperatureStr.c_str());
    mqttClient.publish(topic_publish, temperatureStr.c_str());
}
