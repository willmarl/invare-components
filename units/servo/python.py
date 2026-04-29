from gpiozero import Servo
import time

# gpiozero Servo uses -1 to 1 range (not 0-180 degrees)
servo = Servo(14)


def set_angle(angle):
    """
    Convert angle (0-180) to gpiozero range (-1 to 1)
    0° = -1, 90° = 0, 180° = 1
    """
    # Map 0-180 to -1 to 1
    value = (angle / 90) - 1
    servo.value = value


# Test: cycle through 0, 90, 180
while True:
    for angle in [0, 90, 180]:
        set_angle(angle)
        print(f"Servo moved to: {angle}°")
        time.sleep(1)
