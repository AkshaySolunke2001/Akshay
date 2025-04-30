#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include "Arduino.h"
#include "WiFi.h"
#include "IPAddress.h"

extern "C"
{
    /**
     * @brief Configures the network details for the device.
     *
     * This function attempts to set the IP address, gateway, subnet mask, and DNS
     * addresses for the device using the provided string representations.
     *
     * @param set_ip A string representing the IP address to be set.
     * @param set_gw A string representing the gateway address to be set.
     * @param set_subnet A string representing the subnet mask to be set.
     * @param set_dns A string representing the primary DNS address to be set.
     * @return true if all configurations are successful; false if any configuration fails.
     *
     * The function logs the result of each configuration attempt and returns false
     * if any of the configurations are not successful.
     */
    bool configure_network_details(char *, char *, char *, char *);

    /**
     * @brief Attempt to connect to the specified WiFi network using DHCP.
     *
     * This function disconnects any existing WiFi connection, then
     * attempts to connect to the specified network using the provided
     * SSID and password. The device will obtain an IP address from the
     * network's DHCP server.
     *
     * @param ssid The SSID of the network to connect to.
     * @param pass The password of the network to connect to.
     */
    void connect_to_wifi_dynamic(char *, char *);

    /**
     * @brief Attempt to connect to the specified WiFi network using static IP configuration.
     *
     * This function disconnects any existing WiFi connection, then
     * attempts to connect to the specified network using the provided
     * SSID, password, IP address, gateway, subnet, and DNS server.
     *
     * @param ssid The SSID of the network to connect to.
     * @param pass The password of the network to connect to.
     * @param set_ip The IP address to set for the device.
     * @param set_gw The gateway IP address to set for the device.
     * @param set_subnet The subnet mask to set for the device.
     * @param set_dns The DNS server IP address to set for the device.
     */
    void connect_to_wifi_static(char *, char *, char *, char *, char *, char *);

    /**
     * @brief Get the IP address of the device.
     *
     * This function returns the current IP address assigned to the device
     * by the network. The IP address is returned as a string representation.
     *
     * @return A string representing the device's current IP address.
     */
    String get_ip_address();

    /**
     * @brief Get the current connection status.
     *
     * @return A string indicating the current connection status of the device.
     *         The possible values are:
     *         - "CONNECTED"
     *         - "NO SSID"
     *         - "CONNECTION FAILED"
     *         - "DISCONNECTED"
     *         - "UNKNOWN"
     */
    String get_connection_status();

    /**
     * @brief Retrieves the raw connection status value from the WiFi module.
     *
     * @return The connection status as an integer corresponding to the
     *         wl_status_t enum, which can indicate various states such as
     *         connected, disconnected, etc.
     */
    int get_connection_status_raw();

    /**
     * @brief Returns a string describing the strength of the current connection
     *
     * Returns a string describing the strength of the current connection.
     * The strength is determined by the RSSI (Received Signal Strength Indication)
     * value of the current connection:
     * - STRONG if the RSSI is greater than or equal to -60.
     * - FAIR if the RSSI is less than -60 but greater than or equal to -80.
     * - WEAK if the RSSI is less than -80.
     *
     * @return A string describing the strength of the current connection.
     */
    String get_connection_strength();

    /**
     * @brief Returns the raw RSSI value of the current connection
     *
     * @return The RSSI value, which is a negative number (in decibels).
     */
    int get_connection_strength_raw();

    /**
     * @note Call this function in loop to reconnect to WiFi on disconnection.
     *
     * @brief Reconnects to WiFi using the last used WiFi configuration.
     *
     * If the WiFi connection is not active, this function will attempt to
     * reconnect to the last used WiFi network. If the last used configuration
     * was DHCP, it will call connect_to_wifi_dynamic. If the last used
     * configuration was static, it will call connect_to_wifi_static.
     *
     * @note If the current network mode is AP mode, this function will do nothing.
     */
    void reconnect_to_wifi();

    /**
     * @brief Enables a WiFi hotspot with the given SSID and password.
     *
     * This function sets up the device to operate in Access Point (AP) mode,
     * using the provided SSID and password for the hotspot. It first allocates
     * memory for and stores the SSID and password, then it changes the WiFi
     * mode to AP and starts the hotspot.
     *
     * @param hotspot_ssid The SSID for the hotspot.
     * @param hotspot_pass The password for the hotspot.
     *
     * @note If the memory allocation for SSID or password fails, or if the WiFi
     *       mode change fails, it logs an error and returns without setting up
     *       the hotspot.
     */
    void enable_hotspot(char *, char *);

    /**
     * @brief Retrieves the number of connected clients to the SoftAP.
     *
     * @return uint Number of connected clients.
     */
    uint get_connected_clients();

    /**
     * @brief Retrieves the current network mode.
     *
     * This function returns the current network mode of the device.
     * The possible values are:
     * - WIFI_MODE_STA (1): Station mode
     * - WIFI_MODE_AP (2): Access Point mode
     *
     * @return The current network mode as an integer.
     */
    int get_network_mode();

    /**
     * @brief Disconnects from the currently connected WiFi network.
     *
     * This function logs the SSID of the network being disconnected from
     * and then performs the disconnection operation. It uses the global
     * variable `wifi_ssid` to identify the current network.
     */
    void disconnect_wifi();

    /**
     * @brief Sets the mDNS hostname for the device.
     *
     * This function allocates memory for and assigns the given mDNS name
     * to the global variable `mdns_name`. It then initializes the mDNS
     * service with this name. If the mDNS setup is successful, it logs
     * the configured hostname; otherwise, it logs an error message.
     *
     * @param set_mdns_name The desired mDNS hostname to set.
     *
     * @note If memory allocation for `mdns_name` fails, the function
     *       does not proceed with setting up mDNS.
     */
    void set_mdns(char *);

    /**
     * @brief Gets the IP address of the device in AP mode.
     *
     * This function returns the IP address of the device when it is in AP mode.
     * If the device is not in AP mode, the function returns "0.0.0.0".
     *
     * @return The IP address of the device in AP mode, or "0.0.0.0" if not in AP mode.
     */
    String get_ap_ip();



}

#endif