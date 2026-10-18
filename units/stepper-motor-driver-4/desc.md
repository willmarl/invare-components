TMC2209 stepper driver (V985 carrier) — same step/dir pinout as the TMC2208, plus a UART and StallGuard4 so you can set current in software and do sensorless homing. StealthChop2 is the quiet mode; SpreadCycle is for faster moves. Set the Vref pot before connecting a motor, and put a heatsink on it. Motor supply tops out at 29V — don't feed it the 36V a CNC shield terminal allows.

- Logic Voltage : 3.3V – 5V
- Load Voltage : 4.75V – 29V (12V / 24V typical)
- Current : ~2A RMS / ~2.8A peak with cooling (less without a heatsink)
- Microstepping : 1/8, 1/16, 1/32, 1/64 pin-set, interpolated to 1/256

> AI created desc
