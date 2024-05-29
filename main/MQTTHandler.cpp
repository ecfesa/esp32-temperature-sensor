#include <WiFi.h>
#include "MQTTHandler.h"

const char* mqtt_broker = "104.41.57.13"; // MQTT Broker IP
const int mqtt_port = 1883; // MQTT Broker port
const char* mqtt_id = "fiware_008"; // MQTT ID

WiFiClient espClient;
PubSubClient mqttClient(espClient);

/**
 * Attempts to connect to the MQTT broker.
 * Retries every 2 seconds if the connection fails.
 */
void connectMQTT() {
    while (!mqttClient.connected()) {
        Serial.print("* Attempting to connect to MQTT Broker: ");
        Serial.println(mqtt_broker);
        if (mqttClient.connect(mqtt_id)) {
            Serial.println("Successfully connected to MQTT broker!");
        } else {
            Serial.println("Failed to connect to MQTT broker. Retrying in 2 seconds.");
            delay(2000);
        }
    }
}

/**
 * Initializes the MQTT client and connects to the MQTT broker.
 */
void initMQTT() {
    mqttClient.setServer(mqtt_broker, mqtt_port);
    connectMQTT();
}


/**
 * Checks the current MQTT connection status and reconnects if necessary.
 */
void checkMQTT() {
    if (!mqttClient.connected()) {
        connectMQTT();
    }
}

/**
 * Handles the MQTT client loop.
 * This function should be called regularly in the main loop.
 */
void loopMQTT() {
    mqttClient.loop();
}


