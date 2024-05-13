from machine import Pin, PWM
import time,utime


input1 = PWM(Pin(0))
input2 = PWM(Pin(1))
input3 = PWM(Pin(2))
input4 = PWM(Pin(3))

input1.freq(1000)
input2.freq(1000)
input3.freq(1000)
input4.freq(1000)

power = 10000

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

def forward():
    input1.duty_u16(power)
    input2.duty_u16(0)
    input3.duty_u16(power)
    input4.duty_u16(0)
    print('forward')

def backward():
    input1.duty_u16(0)
    input2.duty_u16(power)
    input3.duty_u16(0)
    input4.duty_u16(power)
    print('backward')

def right():
    input1.duty_u16(0)
    input2.duty_u16(power)
    input3.duty_u16(power)
    input4.duty_u16(0)
    print('right')
    
def left():
    input1.duty_u16(power)
    input2.duty_u16(0)
    input3.duty_u16(0)
    input4.duty_u16(power)
    print('left')

def stopp():
    input1.duty_u16(0)
    input2.duty_u16(0)
    input3.duty_u16(0)
    input4.duty_u16(0)
    print('stop')

while True:
    
    #forward()
    print('forward')
    time.sleep(1)
    
    #backward()
    print('backward')
    time.sleep(1)
    
    #left()
    print('left')
    time.sleep(1)
    
    #right()
    print('right')
    time.sleep(1)
    
    #stopp()
    print('stop')
    time.sleep(1)
    
    distanceR = measure_distance(trigR, echoR)
    distanceL = measure_distance(trigL, echoL)
    
    print("Distance R:", distanceR, "cm")
    print("Distance L:", distanceL, "cm")
    utime.sleep(0.5)
    
    if IR_FR.value() == 1:
        print('on 1')
        time.sleep(0.5)
        
    if IR_FL.value() == 1:
        print('on 2')
        time.sleep(0.5)
    
    if IR_FR.value() == 0:
        print('off 1')
        time.sleep(0.5)

    if IR_FR.value() == 0:
        print('off 2')
        time.sleep(0.5)