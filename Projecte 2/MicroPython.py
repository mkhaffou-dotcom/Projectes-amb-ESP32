print("Hello, World from ESP32 + MicroPython on Wokwi!")
from machine import Pin
import time

led = Pin(2, Pin.OUT)
btn = Pin(4, Pin.IN, Pin.PULL_UP) # idle=1, pressed=0
state = 0
last = 1

while True:
    cur = btn.value()

    Projectes ESP32 amb Wokwi - Mohamed - ICA1101 Pàgina 7
    if last == 1 and cur == 0: # falling edge
        state ^= 1
        led.value(state)
        time.sleep(0.02) # debounce
        while btn.value() == 0: # wait release
            time.sleep(0.01)
    last = cur
    time.sleep(0.01)
