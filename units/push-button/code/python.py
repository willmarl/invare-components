from gpiozero import LED, Button
import time

led = LED(23)
button = Button(24, pull_up=True)

button.when_pressed = led.on
button.when_released = led.off

try:
    while True:
        print(f"Button: {button.is_pressed}, LED: {led.is_lit}")
        time.sleep(0.5)
except KeyboardInterrupt:
    print("\nShutting down...")
    led.off()
