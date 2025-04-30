#include "wifi_config.h"
#include "esp_log.h"
#include "WiFi.h"
#include "ESPmDNS.h"

/* Variable Declarations */

static const char *TAG = "WIFI";

IPAddress wifi_ip;     // Object to store IP Address
IPAddress wifi_gw;     // Object to store Gateway Address
IPAddress wifi_subnet; // Object to store subnet
IPAddress wifi_dns1;   // Object to store DNS1 Address
IPAddress wifi_dns2;   // Object to store DNS2 Address

uint8_t network_mode = 0; // Variable to store Network Mode

uint8_t dhcp_status; // Variable to store DHCP status

char *wifi_ssid; // Variable to store STA SSID
char *wifi_pass; // Variable to store STA Password

char *ap_ssid; // Variable to store AP SSID
char *ap_pass; // Variable to store AP Password

const char *set_dns2 = "8.8.8.8"; // Default DNS

char *mdns_name; // Variable to store mDNS name

bool wifi_init = false; // Variable to store wifi init status

/*****************************/

/* Function Declarations */

/**
 * @brief Initialize WiFi settings and allocate memory for SSID and password.
 *
 * This function sets up the WiFi component by initializing the log levels
 * for WiFi related logs. It also allocates memory for storing the SSID
 * and password for both the STA and AP modes, if they have not been allocated
 * yet. After successful initialization and memory allocation, it sets the
 * wifi_init flag to true.
 *
 * @note The allocated memory for SSID and password is 30 bytes each.
 * @note Initialise wifi related pointer variables in this function.
 * @note Call this function in any entry point functions such as connect_to_wifi_dynamic, connect_to_wifi_static, etc.
 */
void init_wifi();

/**
 * @brief Attempt to connect to the specified WiFi network.
 *
 * This function disconnects any existing WiFi connection, then
 * attempts to connect to the specified network using the provided
 * SSID and password.
 *
 * @param ssid The SSID of the network to connect to.
 * @param pass The password of the network to connect to.
 *
 * @note This function is used in wifi-config.cpp source file only and cannot be called in any other file.
 */

 void connect_to_wifi(char *, char *); // Function to connect to WiFi
/*****************************/

void init_wifi()
{
    ESP_LOGI(TAG, "Initialising WiFi");
    esp_log_level_set("wifi", ESP_LOG_NONE);
    esp_log_level_set("wifi_init", ESP_LOG_NONE);

    if (wifi_ssid == nullptr)
    {
        wifi_ssid = (char *)malloc(30);
        ESP_LOGD(TAG, "[%s: %s: %d] Allocated memory to wifi_ssid", __FILE__, __ASSERT_FUNC, __LINE__);
    }

    if (wifi_pass == nullptr)
    {
        wifi_pass = (char *)malloc(30);
        ESP_LOGD(TAG, "[%s: %s: %d] Allocated memory to wifi_pass", __FILE__, __ASSERT_FUNC, __LINE__);
    }

    if (ap_ssid == nullptr)
    {
        ap_ssid = (char *)malloc(30);
        ESP_LOGD(TAG, "[%s: %s: %d] Allocated memory to ap_ssid", __FILE__, __ASSERT_FUNC, __LINE__);
    }

    if (ap_pass == nullptr)
    {
        ap_pass = (char *)malloc(30);
        ESP_LOGD(TAG, "[%s: %s: %d] Allocated memory to ap_pass", __FILE__, __ASSERT_FUNC, __LINE__);
    }

    wifi_init = true;
}

bool configure_network_details(char *set_ip, char *set_gw, char *set_subnet, char *set_dns)
{
    bool configurations_ok = true; // If any of the configuration fails, this will be set to false

    if (wifi_ip.fromString(set_ip))
    {
        ESP_LOGI(TAG, "Setting IP: %s", (wifi_ip.toString()).c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to parse IP Address");
        configurations_ok = false;
    }

    if (wifi_gw.fromString(set_gw))
    {
        ESP_LOGI(TAG, "Setting Gateway: %s", (wifi_gw.toString()).c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to parse Gateway");
        configurations_ok = false;
    }

    if (wifi_subnet.fromString(set_subnet))
    {
        ESP_LOGI(TAG, "Setting Subnet: %s", (wifi_subnet.toString()).c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to parse Subnet");
        configurations_ok = false;
    }

    if (wifi_dns1.fromString(set_dns))
    {
        ESP_LOGI(TAG, "Setting DNS: %s", (wifi_dns1.toString()).c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to parse DNS");
        configurations_ok = false;
    }

    if (wifi_dns2.fromString(set_dns2))
    {
        ESP_LOGI(TAG, "Configured DNS2: %s", (wifi_dns2.toString()).c_str());
    }
    else
    {
        ESP_LOGE(TAG, "Failed to parse DNS2");
        configurations_ok = false;
    }
    return configurations_ok;
}

void connect_to_wifi(char *ssid, char *pass)
{

    if (wifi_ssid != nullptr)
    {
        strncpy(wifi_ssid, ssid, strlen(ssid) + 1);
        ESP_LOGE(TAG, "configure SSID");
        sys_delay_ms(2000);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to configure SSID");
        return;
    }

    if (wifi_pass != nullptr)
    {
        strncpy(wifi_pass, pass, strlen(pass) + 1);
        ESP_LOGE(TAG, "configure Passward");
        sys_delay_ms(2000);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to configure Password");
        return;
    }

    network_mode = WIFI_MODE_STA;
    ESP_LOGE(TAG, "network_mode = WIFI_MODE_STA selected");
    sys_delay_ms(2000);
    WiFi.disconnect();
    ESP_LOGE(TAG, "wifi disconnected force fully");
    sys_delay_ms(2000);

    WiFi.mode(WIFI_MODE_STA);//udated by akshay
    WiFi.softAP("iam", "RnD@1234567890");//udated by akshay
    WiFi.begin(wifi_ssid, wifi_pass);
    ESP_LOGE(TAG, "Attempting to connect wifi");
    sys_delay_ms(2000);
    delay(500);

    int lp = 0;

    // Wait for WiFi to connect
    while (!WiFi.isConnected())
    {
        ESP_LOGE(TAG, "wifi is not connected");
        sys_delay_ms(2000);
        // ESP_LOGI(TAG, "-|-");
        // delay(500);
        lp++;
        if (lp > 5)
            break;
    }

    if (WiFi.isConnected())
    {
        ESP_LOGI(TAG, "Connected to %s", wifi_ssid);
        delay(1000);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to connect to %s", wifi_ssid);
    }
}

void connect_to_wifi_dynamic(char *ssid, char *pass)
{
    if (!wifi_init)
        init_wifi();

    ESP_LOGI(TAG, "Attempting Connection to %s on DHCP", ssid);

    dhcp_status = 1;

    connect_to_wifi(ssid, pass);
}

void connect_to_wifi_static(char *ssid, char *pass, char *set_ip, char *set_gw, char *set_subnet, char *set_dns)
{
    if (!wifi_init)
        init_wifi();

    ESP_LOGI(TAG, "Attempting Connection to %s using Network Details", ssid);

    dhcp_status = 0;

    if (!configure_network_details(set_ip, set_gw, set_subnet, set_dns))
    {
        ESP_LOGE(TAG, "Failed to parse network details");
        ESP_LOGE(TAG, "Failed to configure Network Details");
        connect_to_wifi_dynamic(ssid, pass);
        return;
    }
    else
    {
        WiFi.config(wifi_ip, wifi_gw, wifi_subnet, wifi_dns1, wifi_dns2);
        IPAddress ip = WiFi.localIP();
        ESP_LOGI(TAG, "Configured IP: %s", ip.toString().c_str());
        connect_to_wifi(ssid, pass);
    }
}

String get_ip_address()
{
    return WiFi.localIP().toString();
}

String get_connection_status()
{
    String status;
    switch (WiFi.status())
    {
    case WL_CONNECTED:
        status = "CONNECTED";
        ESP_LOGE(TAG, "connected");
        sys_delay_ms(2000);
        break;
    case WL_NO_SSID_AVAIL:
        status = "NO SSID";
        ESP_LOGE(TAG, "no ssid");
        sys_delay_ms(2000);
        break;
    case WL_CONNECT_FAILED:
        status = "CONNECTION FAILED";
        ESP_LOGE(TAG, "connection failed");
        sys_delay_ms(2000);
        break;
    case WL_DISCONNECTED:
        status = "DISCONNECTED";
        ESP_LOGE(TAG, "disconnected");
        sys_delay_ms(2000);
        break;
    case WL_CONNECTION_LOST:
        status = "CONNECTION LOST";
        ESP_LOGE(TAG, "connection lost");
        sys_delay_ms(2000);
        break;
    default:
        status = "UNKNOWN";
        ESP_LOGE(TAG, "unknown");
        sys_delay_ms(2000);
    }
    return status;
}

int get_connection_status_raw()
{
    return WiFi.status();
}

String get_connection_strength()
{
    int rssi = WiFi.RSSI();
    String strength;
    if (rssi >= -60)
    {
        strength = "STRONG";
    }
    else if (rssi < -60 && rssi >= -80)
    {
        strength = "FAIR";
    }
    else
    {
        strength = "WEAK";
    }
    return strength;
}

int get_connection_strength_raw()
{
    return WiFi.RSSI();
}

void reconnect_to_wifi()
{

    if (network_mode != WIFI_MODE_STA) // network_mode = 1
    {
        return;
    }

    int status = get_connection_status_raw();

    ESP_LOGI(TAG, "WiFi Connection Status: %d | %s", get_connection_status_raw(), get_connection_status().c_str());
    ESP_LOGI(TAG, "WiFi Connection Strength: %d | %s", get_connection_strength_raw(), get_connection_strength().c_str());

    if (status != WL_CONNECTED)
    {
        if (dhcp_status == 1)
        {
            connect_to_wifi_dynamic(wifi_ssid, wifi_pass);
        }
        if (dhcp_status == 0)
        {
            connect_to_wifi_static(wifi_ssid, wifi_pass, (char *)wifi_ip.toString().c_str(), (char *)wifi_gw.toString().c_str(), (char *)wifi_subnet.toString().c_str(), (char *)wifi_dns1.toString().c_str());
        }
    }
}

void enable_hotspot(char *hotspot_ssid, char *hotspot_pass)
{
    if (!wifi_init)
        init_wifi();

    if (ap_ssid != nullptr)
    {
        strncpy(ap_ssid, hotspot_ssid, strlen(hotspot_ssid) + 1);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to configure SSID");
        return;
    }

    if (ap_pass != nullptr)
    {
        strncpy(ap_pass, hotspot_pass, strlen(hotspot_pass) + 1);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to configure Password");
        return;
    }

    ESP_LOGI(TAG, "Enabling Hotspot: %s", ap_ssid);

    network_mode = WIFI_MODE_AP; // network_mode = 2
    WiFi.disconnect();
    WiFi.mode(WIFI_MODE_AP);
    WiFi.softAP(ap_ssid, ap_pass);
}

uint get_connected_clients()
{
    return WiFi.softAPgetStationNum();
}

int get_network_mode()
{
    return network_mode;
}

void disconnect_wifi()
{
    ESP_LOGI(TAG, "Disconnecting from %s", wifi_ssid);
    network_mode = 0;
    WiFi.disconnect();
}

void set_mdns(char *set_mdns_name)
{

    if (mdns_name == nullptr)
    {
        mdns_name = (char *)malloc(strlen(set_mdns_name) + 1);
    }
    if (!(mdns_name == nullptr))
    {
        strncpy(mdns_name, set_mdns_name, strlen(set_mdns_name) + 1);
    }
    if (MDNS.begin(mdns_name))
    {
        ESP_LOGI(TAG, "Set up mDNS as %s", mdns_name);
    }
    else
    {
        ESP_LOGE(TAG, "Failed to setup mDNS");
    }
}

String get_ap_ip()
{
    if (network_mode == 2)
    {
        return ((WiFi.softAPIP()).toString());
    }
    return "0.0.0.0";
}