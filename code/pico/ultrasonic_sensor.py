#Source: Electrocredible.com, Language: MicroPython
from machine import Pin
import time
trigger_pin=14
echo_pin=15
trigger=Pin(trigger_pin, Pin.OUT)
echo=Pin(echo_pin, Pin.IN)
led = Pin(16,Pin.OUT)

while True:
    trigger.high()
    time.sleep_us(10)
    trigger.low()
    while (echo.value()==0):
        pass #wait for echo
    lastreadtime=time.ticks_us() # record the time when signal went HIGH
    while (echo.value()==1):
        pass #wait for echo to finish
    echotime=time.ticks_us()-lastreadtime
    distance = (echotime * 0.034) / 2
    print("Obstace distance= {}cm".format(distance))
    if distance > 15:
        print("far")
        led.value(0)
    else:
        print("near")
        led.value(1)
    time.sleep(0.01)