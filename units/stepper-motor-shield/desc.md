CNC Shield V3 for an Arduino Uno. Four sockets (X, Y, Z, A) take A4988, DRV8825, or TMC step/dir drivers — drivers are not on the board. Motor power goes in the blue 12–36V terminal; 5V logic comes from the Uno. Line the driver's EN pin up with the socket EN, and set each driver's current before you seat it. A4988 should stay at 24V or under, TMC2209 at 29V or under, even though the silkscreen says 36V. Don't plug or unplug a motor while power is on.

- Logic : 5V from the Uno
- Motor supply : 12V – 36V (A4988 ≤24V, TMC2209 ≤29V)
- Axes : X, Y, Z, plus A (cloned axis, or D12/D13 on some boards)
- Step / dir : X 2/5, Y 3/6, Z 4/7, enable 8 (active low)

> AI created desc
