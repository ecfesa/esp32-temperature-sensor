#pragma once

#include <PubSubClient.h>

extern PubSubClient mqttClient;

/**
 * Initializes the MQTT client and connects to the MQTT broker.
 */
void initMQTT();

/**
 * Checks the current MQTT connection status and reconnects if necessary.
 */
void checkMQTT();

/**
 * Handles the MQTT client loop.
 * This function should be called regularly in the main loop.
 */
void loopMQTT();
