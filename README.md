# Nixie Clock
Atmega328p based Nixie Clock with RTC module

## Main features 
- Six digit display
- Two buttons for settinn the time
- AC powered, internal AC-DC converter
- DS3231 RTC module with button battery that keeps time even when the Nixie Clock is not powered

## Description of folders
- Boost_converter: In here you can find a simple program for AtTiny45 which works as PWM controler for boost converter mosfet
- Nixie_control: I here is the main program written for Atmega328p. It drives the Nixie tubes, reads the time from RTC module and it checks the buttons.
- Documents: Schematics and PCBs. Project was split into two PCB, one for Nixie tubes and k155id1 drivers and the other one for everything else.