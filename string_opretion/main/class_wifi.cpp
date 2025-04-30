#include "wifi_config.h"
#include "esp_log.h"
#include "WiFi.h"
#include "ESPmDNS.h"

# include "class_wifi.h"


class_wifi::class_wifi(const char *ssid, const char *pass)
{ 
    // wifi inti start
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
    // wifi inti complite


 // connect to wifi


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

    WiFi.mode(WIFI_MODE_STA);
    WiFi.begin(wifi_ssid, wifi_pass);
    ESP_LOGE(TAG, "Attempting to connect wifi");
    sys_delay_ms(2000);
    delay(500);
    int lp = 0;

    // Wait for WiFi to connect


    ESP_LOGI(TAG, "Attempting Connection to %s on DHCP", ssid);

    dhcp_status = 1;


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


