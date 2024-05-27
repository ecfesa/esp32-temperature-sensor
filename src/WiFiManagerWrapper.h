#pragma once

/**
 * Initializes the Wi-Fi manager and attempts to connect to a saved Wi-Fi network.
 * If no saved network is found, it creates an access point for Wi-Fi configuration.
 */
void initWiFi();

/**
 * Checks the current Wi-Fi connection status and reconnects if necessary.
 */
void checkWiFi();
