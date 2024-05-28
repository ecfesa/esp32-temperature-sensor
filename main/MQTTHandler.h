#pragma once

#include "lib/PubSubClient/PubSubClient.h"

extern PubSubClient mqttClient;

/**
 * Initializes the MQTT client and connects to the MQTT broker.
 */
void initMQTT();

/**
 * Checks the current MQTT connection status and reconnects if necessary.
 */
void checkMQTT();
