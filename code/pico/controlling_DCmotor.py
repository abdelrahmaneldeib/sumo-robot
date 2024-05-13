from machine import Pin, PWM, ADC
import time

in1 = PWM(Pin(14))
in2 = PWM(Pin(15))
#in3 = PWM(Pin(16))
#in4 = PWM(Pin(17))

adc = ADC(Pin(26))

in1.freq(1000)
in2.freq(1000)

while True:
    power = adc.read_u16()
    print(power)
    in1.duty_u16(power)
    in2.duty_u16(0)
    #in3.duty_u16(power)
    #in4.duty_u16(0)
    time.sleep(0.1)
