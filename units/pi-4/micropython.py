import machine

led = machine.Pin("LED", machine.Pin.OUT)
led_state = False

while True:
    led.value(led_state)

    user_input = input().strip()

    if user_input == "on":
        led_state = True
    elif user_input == "off":
        led_state = False

    print(f"LED is {led_state} | you typed: {user_input}")
