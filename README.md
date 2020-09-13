# What is ESP8266 ?

The ESP8266 series, or family, of Wi-Fi chips is produced by Espressif Systems, 
a fabless semiconductor company operating out of Shanghai, China.
The ESP8266 series presently includes the ESP8266EX and ESP8285 chips.

ESP8266EX (simply referred to as ESP8266) is a system-on-chip (SoC) which integrates a 32-bit Tensilica microcontroller, 
standard digital peripheral interfaces, antenna switches, RF balun, power amplifier, low noise receive amplifier, 
filters and power management modules into a small package. 
It provides capabilities for 2.4 GHz Wi-Fi (802.11 b/g/n, supporting WPA/WPA2),
general-purpose input/output (16 GPIO), Inter-Integrated Circuit (I²C), 
analog-to-digital conversion (10-bit ADC), Serial Peripheral Interface (SPI),
I²S interfaces with DMA (sharing pins with GPIO), UART 
(on dedicated pins, plus a transmit-only UART can be enabled on GPIO2), 
and pulse-width modulation (PWM). The processor core, called "L106" by Espressif, 
is based on Tensilica's Diamond Standard 106Micro 32-bit processor controller core and runs at 80 MHz 
(or overclocked to 160 MHz). It has a 64 KiB boot ROM, 32 KiB instruction RAM, and 80 KiB user data RAM. 
(Also, 32  KiB instruction cache RAM and 16 KiB ETS system data RAM.) External flash memory can be accessed through SPI.
The silicon chip itself is housed within a 5 mm × 5 mm Quad Flat No-Leads package with 33 connection pads —
8 pads along each side and one large thermal/ground pad in the center.


For this project only D7 pin has been used.

# Sample Usage:

-------------------------------------
http://192.168.1.110/pin7/off
http://192.168.1.110/pin7/on

# For help:
------------------
http://192.168.1.110

