**TLDR** : function returns the **frequency** of the light detected for each color channel
The sensor itself doesn't directly measure wavelength; instead, it has physical color filters (red, green, blue) that block certain wavelengths and let others through to the photodiodes.

calibrate by establishing a **reference point**:

1. **White calibration** — Place a white or reflective surface in front of the sensor and measure the frequency values. This gives you the maximum expected frequency for each color.
2. **Black calibration** — Place a black or non-reflective surface in front and measure. This gives you the minimum.
3. **Then for any color**, you normalize its frequency against these calibration values to get a 0-255 RGB equivalent.
