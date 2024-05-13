import machine
from machine import Pin, PWM
import utime
from hcsr04 import HCSR04



IR_FR = Pin(3, Pin.IN)  # front right ir
IR_FL = Pin(2, Pin.IN)  # front left ir
IR_RB = Pin(4, Pin.IN)  # right bottom ir
IR_LB = Pin(5, Pin.IN)  # left bottom ir
IR_RT = Pin(26, Pin.IN)  # right top ir
IR_LT = Pin(27, Pin.IN)  # left top ir
input1 = PWM(Pin(5))  # input of motor
input2 = PWM(Pin(6))  # input of motor
input3 = PWM(Pin(9))  # input of motor
input4 = PWM(Pin(10))  # input of motor
ultrasonic = HCSR04(trigger_pin=Pin(0), echo_pin=Pin(1))  # trig, echo

power = 200
at_start = True

def forward():
    input1.duty_u16(int(power * 1.1))
    input2.duty_u16(0)
    input3.duty_u16(power)
    input4.duty_u16(0)

def backward():
    input1.duty_u16(0)
    input2.duty_u16(int(power * 1.1))
    input3.duty_u16(0)
    input4.duty_u16(power)

def right():
    input1.duty_u16(0)
    input2.duty_u16(int(power * 1.1))
    input3.duty_u16(power)
    input4.duty_u16(0)

def left():
    input1.duty_u16(int(power * 1.1))
    input2.duty_u16(0)
    input3.duty_u16(0)
    input4.duty_u16(power)

def stopp():
    input1.duty_u16(0)
    input2.duty_u16(0)
    input3.duty_u16(0)
    input4.duty_u16(0)

while True:
    distance = ultrasonic.distance_cm()
    print("Distance:", distance)
    utime.sleep_ms(200)

    if IR_RT.value() == 1 or IR_LT.value() == 1:
        backward()
        print("back")
        continue

    if distance < 40 and IR_FL.value() != 1 and IR_FR.value() != 1:
        forward()
        print("front")
        at_start = False
    elif IR_FL.value() == 1 and IR_FR.value() == 0:
        right()
        print("right")
    elif (IR_FL.value() == 0 and IR_FR.value() == 1) or at_start:
        left()
        print("left")
    else:
        continue