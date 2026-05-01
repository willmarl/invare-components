from gpiozero import LED

led = LED(23)  # GPIO23
led_state = False

try:
    while True:
        led.on() if led_state else led.off()

        user_input = input().strip()

        if user_input == "on":
            led_state = True
        elif user_input == "off":
            led_state = False

        print(f"LED is {led_state} | you typed: {user_input}")

except KeyboardInterrupt:
    print("\nExiting...")
