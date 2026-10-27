# ESP32 DHT22 Micropython example
from machine import Pin
from time import sleep
import dht

dht = dht.DHT22(Pin(17))

while True:
    try:
        dht.measure()
        print(dht.temperature())
        print(dht.humidity())
        sleep(2)
    except OSError as e:
        print('Oops')
