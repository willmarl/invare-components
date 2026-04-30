from machine import Pin
import time

# Pin for the IR receiver output
ir_receiver_pin = Pin(1, Pin.IN)

while True:
    sensor_value = ir_receiver_pin.value()
    if sensor_value == 0:  # LOW
        print("Object Detected!")
    else:
        print("Clear")
    time.sleep(0.1)  # 100ms delay
