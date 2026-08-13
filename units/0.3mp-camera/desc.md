Low-resolution OV7670 VGA camera. Needs a lot of GPIO for the parallel data bus (D0–D7 plus PCLK/VSYNC/HREF) plus SCCB (I2C-like) for config. FIFO versions are easier because they buffer a frame; without FIFO the MCU has to grab pixels in real time.

- Operating Voltage : 3.3V (do not feed 5V into the sensor)
- Resolution : 640×480 (VGA), ~30 fps max
- Interface : 8-bit parallel + SCCB

> AI created desc
