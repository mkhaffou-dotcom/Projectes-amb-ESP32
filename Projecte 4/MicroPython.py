# Control the brightness of an LED (GPIO 4) with a potentiometer (GPIO 34)
from machine import Pin, ADC, PWM
from time import sleep

pot = ADC(Pin(34))
led = PWM(Pin(4))

pot.width(ADC.WIDTH_12BIT)
pot.atten(ADC.ATTN_11DB)

while True:
    pot_value = pot.read()
    duty_cycle = pot_value // 16
    led.duty(duty_cycle)
    print(duty_cycle)
    sleep(0.1)
