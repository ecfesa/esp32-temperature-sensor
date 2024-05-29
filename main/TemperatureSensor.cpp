#include <Arduino.h>
#include "MQTTHandler.h"

const int temp_sensor_pin = 25; // Temperature sensor analog pin
const char* topic_publish = "/TEF/temp008/attrs"; // MQTT topic to publish temperature data

// Table of values discovered from experimentation
static const int sensorValues[] = {
    541,  561,  639,  718,  794,  905,  983,  1003, 1111, 1200, 1236, 1344,
    1390, 1466, 1572, 1605, 1719, 1760, 1833, 1934, 2016, 2066, 2131, 2231};
static const float temperatures[] = {
    18.5, 20.0, 22.0, 24.0, 26.0, 28.0, 30.0, 32.0, 34.0, 36.0, 38.0, 40.0,
    42.0, 44.0, 46.0, 48.0, 50.0, 52.0, 54.0, 56.0, 58.0, 60.0, 62.0, 64.0};
static const int numValues = sizeof(sensorValues) / sizeof(sensorValues[0]);

float interpolateTemperature(int sensorValue) {
    // If the sensorValue is out of bounds, return the closest temperature
    if (sensorValue <= sensorValues[0]) {
        return temperatures[0];
    } else if (sensorValue >= sensorValues[numValues - 1]) {
        return temperatures[numValues - 1];
    }

    // Find the two surrounding points
    for (int i = 0; i < numValues - 1; ++i) {
        if (sensorValue >= sensorValues[i] && sensorValue <= sensorValues[i + 1]) {
            // Linear interpolation
            float t1 = temperatures[i];
            float t2 = temperatures[i + 1];
            int s1 = sensorValues[i];
            int s2 = sensorValues[i + 1];
            return t1 + (t2 - t1) * (sensorValue - s1) / float(s2 - s1);
        }
    }

    // Default return (should not reach here if the input is within range)
    return 0.0;
}

/**
 * Reads the temperature from the analog sensor and publishes the data to the MQTT broker.
 * Converts the analog sensor value to a voltage, then to a temperature in degrees Celsius.
 */
void handleTemperature() {
    int sensorValue = analogRead(temp_sensor_pin);
    float temperature = sensorValue;
    String temperatureStr = String(temperature);
    Serial.print("Temperature value: ");
    Serial.println(temperatureStr.c_str());
    mqttClient.publish(topic_publish, temperatureStr.c_str());
    Serial.println("Sleeping for 100ms");
    delay(100);
}
