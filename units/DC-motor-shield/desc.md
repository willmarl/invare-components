L293D Arduino motor shield (MH Electronics). Drives up to 4 DC motors or 2 steppers plus 2 servos. Uses a 74HC595 so it eats fewer Arduino pins, but you need the AFMotor / equivalent library. Requires external motor power — do not run motors off the Arduino 5V pin.

- Logic Voltage (from Arduino) : 5V
- Load Voltage (EXT_PWR) : 4.5V – 25V (6V – 12V typical)
- Current per channel : 600mA continuous, 1.2A peak
- Caveat : ~1.4V drop inside the L293D, so motors see less than EXT_PWR

> AI created desc
