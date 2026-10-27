# Modificacio: escalat correcte (0-1023) + percentatge
from machine import Pin, ADC, PWM
from time import sleep

pot = ADC(Pin(34))
led = PWM(Pin(4))

pot.width(ADC.WIDTH_12BIT)
pot.atten(ADC.ATTN_11DB)

while True:
    pot_value = pot.read() # 0 - 4095
    duty_cycle = pot_value // 4 # 0 - 1023
    led.duty(duty_cycle)
    percent = pot_value * 100 // 4095
    print("Lectura:", pot_value, "| Brillantor:", percent, "%")
    sleep(0.2)
