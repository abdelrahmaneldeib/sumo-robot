from machine import Pin
import time
#interrupt_flag=0
#debounce_time=0
pin = Pin(26, Pin.IN, Pin.PULL_UP)
led = Pin("LED", Pin.OUT)
counter=0

def callback(pin):
    global counter
    counter += 1

pin.irq(trigger=Pin.IRQ_HIGH_LEVEL, handler=callback)

while True:
    if counter % 2 == 0:
        led.value(1)
    else:
        led.value(0)
