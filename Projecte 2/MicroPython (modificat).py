# Modificacio: comptador de pulsacions
from machine import Pin
import time

led = Pin(2, Pin.OUT)
btn = Pin(4, Pin.IN, Pin.PULL_UP)
state = 0
last = 1
count = 0

while True:
    cur = btn.value()
    if last == 1 and cur == 0:
        state ^= 1
        led.value(state)
        count += 1
        print("Pulsacions:", count, "| LED", "ON" if state else "OFF")
        time.sleep(0.02)
        while btn.value() == 0:
            time.sleep(0.01)
    last = cur
    time.sleep(0.01)
