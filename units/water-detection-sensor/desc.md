It's a **water detector (how wet)**, not position-based.
The sensor has **exposed traces/pads** on the board. When water touches those pads, it completes a circuit and changes the resistance, which changes the analog reading.
**It detects:**

- ✅ How wet the sensor pads are
- ✅ Water droplets on it
- ✅ Rain/moisture
- ❌ Water level at a specific height (that's a different sensor type like ultrasonic)
  **What the values mean:**
- **0-100**: Dry (no water contact)
- **100-500**: Damp (light moisture)
- **500+**: Wet (water touching pads)
