ESP32 with onboard OV2640 camera and microSD slot. Power it from a solid 5V supply (aim for 5V 2A) — 3.3V often brownouts and puts water-line artifacts on the image. GPIO0 to GND to flash firmware; leave GPIO0 floating when running. Camera eats most GPIOs so leftover I/O is limited.

- Operating Voltage : 5V recommended (4.75V – 5.25V)
- Camera : OV2640 (up to 1600×1200)
- Current : ~180mA idle, ~310mA with flash on
- Programming : needs an external USB-to-TTL adapter

> AI created desc
