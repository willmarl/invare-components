from machine import Pin, PWM
import time

servo_pin = Pin(28)
servo = PWM(servo_pin)
servo.freq(50)


def set_angle(angle):
    angle = max(0, min(180, angle))
    pulse_width_us = 1000 + (angle / 180) * 1000
    duty = int((pulse_width_us / 20000) * 65535)
    servo.duty_u16(duty)


# Test: cycle through 0, 90, 180
while True:
    for angle in [0, 90, 180]:
        set_angle(angle)
        print(f"Servo moved to: {angle}°")
        time.sleep(1)
