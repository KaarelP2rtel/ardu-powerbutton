# Arduino powerbutton
This is an arduino PC power button interceptor.

This is intended to be used as a cat-proof power button for a desktop PC requiring multiple presses to register an actual power button press. It can also act as a reset button for cases that do not have one. I used an Arduino Nano, but the same code works for the Uno aswell.

The Arduino can be powered via any 5V connection from the motherboard that retains power after shutdown. For example  I used the 5V pin from the motherboard's front USB2.0 header which on my board is powered even when shut down. If no such pin is available, a jumper could also be inserted into the 5VSB pin on the 24pin plug. For the GND, the same USB header GND or any other ground connection can be used.

# Usage
Press 3 times to "tap the power button once"

Press 3 times and hold to "hold the power button"

Press 5 times to "tap the reset button once"

# Connections
PC Case PowerSW jumper to pins D2 and GND

MB PowerSW+ pin to D3

MB ResetSW+ pin to D4

A ground connection to GND

A 5V power source to 5V

MB HDD to D7 ( Either HDD+ or HDD- depending on which pin is used to drive the LED)

PC Case LED+ to D8 via a 160ohm resistor
PC Case LED- to GND


