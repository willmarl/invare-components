AS5600 contactless angle sensor (HW-993). It reads the angle of a diametric magnet sitting over the chip — not a clicky quadrature encoder. I2C address is fixed at `0x36`, so only one of these on the bus. `OUT` is analog or PWM if you don't want I2C, and `DIR` flips which way the angle counts. Center the magnet and keep the gap small; an axial or weak magnet just reads noise.

- Operating Voltage : 3.3V or 5V (match the MCU)
- Interface : I2C `0x36`, plus analog / PWM out
- Resolution : 12-bit (4096 counts / rev)
- Magnet gap : ~0.5 – 3 mm, diametrically magnetized

> AI created desc
