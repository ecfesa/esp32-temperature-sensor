#include "WiFiManager/WiFiManager.h"
#include "WiFiManagerWrapper.h"

WiFiManager wifiManager;

/**
 * Initializes the Wi-Fi manager and attempts to connect to a saved Wi-Fi network.
 * If no saved network is found, it creates an access point for Wi-Fi configuration.
 */
void initWiFi() {
    wifiManager.autoConnect("ESPTemp_ConfigAP");
    Serial.println("Connected to WiFi");
}

/**
 * Checks the current Wi-Fi connection status and reconnects if necessary.
 */
void checkWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        wifiManager.autoConnect("ESP32_ConfigAP");
    }
}
