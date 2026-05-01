from gpiozero import MotionSensor
import time

# Pin for the IR receiver output
ir_receiver = MotionSensor(23)

try:
    while True:
        if not ir_receiver.is_active:
            print("Object Detected!")
        else:
            print("Clear")
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Exiting...")
finally:
    ir_receiver.close()
