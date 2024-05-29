#pragma once

/**
 * Should be run in the main loop.
 * Reads the temperature from the analog sensor and publishes the data to the MQTT broker every second.
 */
void loopTemperature();
