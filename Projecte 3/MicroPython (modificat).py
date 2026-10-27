# Modificacio: LED d'alarma + sortida formatada
from machine import Pin
from time import sleep
import dht

sensor = dht.DHT22(Pin(17)) # nom diferent del modul dht
alarm = Pin(2, Pin.OUT)
LIMIT = 30 # graus C

while True:
    try:
        sensor.measure()
        t = sensor.temperature()
        h = sensor.humidity()
        print("Temperatura: {} C | Humitat: {} %".format(t, h))
        alarm.value(1 if t > LIMIT else 0)
    except OSError:
        print("Error de lectura del sensor")
    sleep(2)
