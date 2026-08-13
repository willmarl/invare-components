USB–UART bridge (CP2102) for serial console / flashing boards that don't have USB (ESP32-CAM, etc.). Check the 3.3V/5V jumper so TX/RX match the target MCU — 5V serial into a 3.3V chip can kill it. The 3.3V pin is only good for a little current, not powering a whole board.

- USB side : 5V
- UART logic : 3.3V or 5V (jumper)
- 3.3V pin current : ~50–100mA max

> AI created desc
