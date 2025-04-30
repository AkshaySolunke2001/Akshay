#ifndef CLASS_WIFI_H
#define CLASS_WIFI_H


static const char *TAG = "WIFI";
class class_wifi
{
private:
char *wifi_ssid = nullptr; // Variable to store STA SSID
char *wifi_pass = nullptr; // Variable to store STA Password

char *ap_ssid = nullptr; // Variable to store AP SSID
char *ap_pass = nullptr; // Variable to store AP Password
uint8_t network_mode = 0; // Variable to store Network Mode
uint8_t dhcp_status; // Variable to store DHCP status
bool wifi_init = false;
public:
    class_wifi(const char *ssid, const char *pass);
   
};





#endif