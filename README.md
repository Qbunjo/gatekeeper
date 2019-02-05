# gatekeeper for arduino

This program was created to inform if the house gates (main gate and garage gate) are open.<br>
The information is printed on the standard LCD 16x2, also when any of the gates is open, it beeps with buzzer.

Inputs:

* Pin 7, Pin 8 (sensor at the gates shorted to GND when open), normally shorted to VCC through pull-up resistor.

Outputs:

* Pins: 12, 11, 5, 4, 3, 2 - LCD
* Pin 10: Buzzer

TODO:
web server displaying status in local network build on ESP8266.
Connected with arduino by virtual serial port (RX-TX pins).
Thanks to this information on the website will always be up to date.
