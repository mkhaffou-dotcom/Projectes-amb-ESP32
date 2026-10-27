# Modificacio: senyal SOS en codi morse
from machine import Pin
from utime import sleep_ms

led = Pin(21, Pin.OUT)
SHORT_MS = 200
LONG_MS = 600
GAP_MS = 200

def pulse(ms):
    led.on()
    sleep_ms(ms)
    led.off()
    sleep_ms(GAP_MS)

while True:
    print("SOS")
    for d in (SHORT_MS,) * 3 + (LONG_MS,) * 3 + (SHORT_MS,) * 3:
        pulse(d)
    sleep_ms(1500)
