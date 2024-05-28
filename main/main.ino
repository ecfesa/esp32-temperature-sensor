#include <Arduino.h>
#include "WiFiManagerWrapper.h"
#include "MQTTHandler.h"
#include "TemperatureSensor.h"

const int led_pin = 2; // Onboard LED pin

void setup() {
    Serial.begin(115200);
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);

    // Initialize Wi-Fi and MQTT
    initWiFi();
    initMQTT();
}

void loop() {
    checkWiFi();
    checkMQTT();
    handleTemperature();
    mqttClient.loop();
}
