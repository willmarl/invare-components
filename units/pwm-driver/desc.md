16 channel, I2C-bus controlled driver used to control PWM modules. Requires external power that is separate from from the logic power.

- Logic Voltage (Input from microcontroller): 2.3V - 5.5V
- Load Voltage (Power that the pin from driver can handle): 6V

### How it works:

- **Servo 1 (Channel 0)**: Uses `setPWM()` directly for instant jumps (410 → 615 → 820)
- **Servo 2 (Channel 1)**: Uses `smoothServo()` function that ramps PWM value gradually over time
  **Servo PWM values:**
- 410 = 0°
- 615 = 90°
- 820 = 180°
  **Adjust smoothness:**
- More `steps` = smoother motion (slower)
- Fewer `steps` = jerkier but faster

### Calculating current draw

**Typical servo current draw:**

- Idle (holding position): ~10-20mA per servo
- Moving (no load): ~100-200mA per servo
- Stalled (max load): ~500-800mA per servo
  **Rule of thumb:**
- **Assume worst case: 500mA per servo**
- Safety margin: multiply by 1.5x

```
Total current = (Number of servos) × (Average current per servo)
```

Example with MG90S:

- 4 servos × 500mA average = 2000mA (2A supply needed)
- 12 servos × 500mA average = 6000mA (6A supply needed)

Another example of 2 micro servos, 1 20kg servo, and 1 40kg servo

```
Total current = Sum of all servo stall currents + safety margin

MG90S: ~900mA stall × 2 = 1800mA
20kg servo: ~2000mA stall × 1 = 2000mA
40kg servo: ~3000mA stall × 1 = 3000mA
─────────────────────────────────
Subtotal = 6800mA (6.8A)

Add 20% safety margin:
6800mA × 1.2 = 8160mA (8.16A)

Get a power supply rated for at least 10A @ 5-6V
```
