Logic-level N-channel MOSFET (IRLZ44N) for switching higher-current DC loads from a microcontroller. Gate threshold is low enough for 5V GPIO; 3.3V will turn it on but with higher Rds(on)/heat. Put a ~100Ω gate resistor and a pull-down so it doesn't float. Use a heatsink if you're actually pushing amps.

- Type : N-channel, logic-level
- Drain-Source Voltage : 55V
- Continuous Current : 47A (with proper cooling — the TO-220 package is the real limit)
- Rds(on) : ~0.022Ω @ 10V gate, ~0.025Ω @ 5V gate
- Gate Threshold : 1V – 2V

> AI created desc
