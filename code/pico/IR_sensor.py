from machine import Pin
import time

led = Pin(16,Pin.OUT)
sensor = Pin(17,Pin.IN)

while True:
    if sensor.value() == 1:
        led.value(1)
        print('on')
        time.sleep(0.1)
    if sensor.value() == 0:
        led.value(0)
        time.sleep(0.1)
        print('off')
