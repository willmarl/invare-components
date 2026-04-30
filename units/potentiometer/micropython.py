from machine import ADC, Pin
import time

# GPIO26 is ADC0 on Pico (adjust if using different pin)
pot_pin = ADC(0)

while True:
    pot_value = pot_pin.read_u16()  # Read 16-bit value (0-65535)
    voltage = (pot_value / 65535.0) * 3.3  # Convert to voltage (0-3.3V)

    print(f"Raw: {pot_value} | Voltage: {voltage:.2f} V")

    time.sleep(0.1)  # Wait 100ms before next read
