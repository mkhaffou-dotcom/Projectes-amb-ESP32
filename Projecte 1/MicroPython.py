# 07.10 - LED blink with loop (GPIO 21)
from machine import Pin
from utime import sleep_ms

led = Pin(21, Pin.OUT) # create output pin on GPIO21

while True:
    led.on()
    sleep_ms(100)
    led.off()
    sleep_ms(200)
