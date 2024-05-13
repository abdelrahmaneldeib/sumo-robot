#this code contain all the motion fuctions needed

from machine import Pin, PWM
import time

input1 = PWM(Pin(0))
input2 = PWM(Pin(1))
input3 = PWM(Pin(2))
input4 = PWM(Pin(3))
input1.freq(1000)
input2.freq(1000)
input3.freq(1000)
input4.freq(1000)

power = 10000

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
    forward()
    time.sleep(1)
    backward()
    time.sleep(1)
    left()
    time.sleep(1)
    right()
    time.sleep(1)
    stopp()
    time.sleep(1)
    