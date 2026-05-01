from machine import Pin
import time

LED_PIN = 25
BUTTON_PIN = 2

# Initialize pins
led = Pin(LED_PIN, Pin.OUT)
button = Pin(BUTTON_PIN, Pin.IN, Pin.PULL_UP)

while True:
    # PULL_UP inverts logic: 0 (LOW) means pressed
    button_state = button.value()

    if button_state == 0:  # Button pressed
        led.on()
    else:
        led.off()

    time.sleep(0.01)  # Small delay to prevent blocking
