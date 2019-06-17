import PRi.GPIO as GPIO
import time
import serial
from firebase import
firebase = firebase.FirebaseApplication(https://gun2016-a98af.firebaseio.com/"$

ser = serial.Serial('dev/ttyAM0'.9600)
#ser.open()

while(True):
	result = firebase.get('/test','test')
	ser.write(str(result))
	print result