#include "Arduino.h"
#include "wifi_config.h"
#include "class_wifi.h"
#include <string.h>

 const char* ssid = "Akshay";
 const char* pass = "12345678";

extern "C" void app_main()
{
      // Start serial communication at 115200 baud rate
      Serial.begin(115200);
    
      // Wait until the serial monitor is ready
      while (!Serial) {
          // Wait for the serial port to connect (needed for native USB)
      }

    initArduino();

    char s1;
    char s2;
    char s3;
    
    Serial.print(strcpy(s1,ssid));
    Serial.print(strncpy(s2,s1,3));
    memcpy(s3,pass,2);
    Serial.print(s3);
    Serial.print(s3,s2);





    class_wifi obj(ssid, pass);

    Serial.println("networkmode");
    Serial.println(get_network_mode());

    get_connection_status();

    Serial.println(get_connection_status_raw());
    Serial.println(get_connection_strength());
    
    Serial.println(get_ip_address());

    delay(2000);

    Serial.println("networkmode");
    Serial.println(get_network_mode());

   

}
