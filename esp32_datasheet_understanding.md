# esp32 data sheet understanding  
in this document i am writing all about esp32 which i understand during reading datasheet  
  
  
    
## Key features

- wifi (802.11b/g/n, 802.11n (2.4 GHz), up to 150 Mbps)  
- bluetooth   
- 448 KB ROM  
- 520 KB SRAM  
- 16 KB SRAM in RTC  
- QSPI supports multiple flash/SRAM chips  
- Internal 8 MHz oscillator with calibration  
- Internal RC oscillator with calibration  
- External 2 MHz ~ 60 MHz crystal oscillator (40 MHz only for Wi-Fi/Bluetooth functionality)  
- External 32 kHz crystal oscillator for RTC with calibration  
- Two timer groups, including 2 × 64-bit timers and 1 × main watchdog in each group  
- One RTC timer    
- RTC watchdog    
- 34 programmable GPIOs    
 - Five strapping GPIOs    
 - Six input-only GPIOs    
 - Six GPIOs needed for in-package flash (ESP32-U4WDH) and in-package PSRAM (ESP32-D0WDR2-V3)    
- 12 bit SAR ADC up to 18 channels   
- two 8 bit DAC  
- 10 touch sensors  
- 4 SPI interfase  
- 2 i2c interfaces   
- 3 UART interfaces   
- One host (SD/eMMC/SDIO)  
- One slave (SDIO/SPI)  
- Ethernet MAC interface with dedicated DMA and IEEE 1588 support  
- RMT (TX/RX)  
- LED PWM up to 16 channels  
- Motor PWM  
- Five power modes designed for typical scenarios: Active, Modem-sleep, Light-sleep, Deep-sleep,
Hibernation  
- Power consumption in Deep-sleep mode is 10 µA  
- Ultra-Low-Power (ULP) coprocessors  
- RTC memory remains powered on in Deep-sleep mode   
### Electrical Characteristics
**opreting voltage is 2.3 to 3.3 volt**  
**its recommended output current is 500 mA**   



   
#### Boot and Flashing Info











