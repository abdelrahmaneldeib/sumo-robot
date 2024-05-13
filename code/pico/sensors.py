#this code contain the functions of all sensors used

from machine import Pin
import time,utime


IR_FR = Pin(4, Pin.IN)  # front right ir
IR_FL = Pin(5, Pin.IN)  # front left ir
IR_RB = Pin(6, Pin.IN)  # right bottom ir
IR_LB = Pin(7, Pin.IN)  # left bottom ir

trigR = Pin(8, Pin.OUT)  # right ultrasonic trigger
echoR = Pin(9, Pin.IN)	 # right ultrasonic echo
trigL = Pin(10, Pin.OUT) # left ultrasonic trigger
echoL = Pin(11, Pin.IN)	 # left ultrasonic echo

def measure_distance(trigger_pin, echo_pin):
    
    trigger_pin.high()
    utime.sleep_us(10)
    trigger_pin.low()

    while echo_pin.value() == 0:
        pulse_start = utime.ticks_us()
    while echo_pin.value() == 1:
        pulse_end = utime.ticks_us()

    pulse_duration = utime.ticks_diff(pulse_end, pulse_start)
    distance = pulse_duration * 0.0343 / 2  

    return distance


while True:
    
    distanceR = measure_distance(trigR, echoR)
    distanceL = measure_distance(trigL, echoL)
    print("Distance R:", distanceR, "cm")
    print("Distance L:", distanceL, "cm")
    utime.sleep(0.1)
    