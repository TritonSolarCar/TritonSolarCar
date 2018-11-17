#simple script for user to enter 1 or 0 to turn arduino light on or off

import serial                                       #Serial imported for Serial communication
import time                                         #Required to use delay functions   
ArduinoUnoSerial = serial.Serial(
    port='COM4',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1 
)       #Create Serial port object called ArduinoUnoSerialData time.sleep(2)                                                             #wait for 2 secounds for the communication to get established
print ArduinoUnoSerial.readline()                   #read the serial data and print it as line 
print ("You have new message from Arduino")
while 1:    #Do this forever
    var = raw_input()                                   #get input from user             
    if (var == '1'):                                    #if the value is 1         
        ArduinoUnoSerial.write('1')                     #send 1 to the arduino's Data code       
        print ("LED turned ON")         
        time.sleep(1)          
    if (var == '0'): #if the value is 0         
        ArduinoUnoSerial.write('0')                     #send 0 to the arduino's Data code    
        print ("LED turned OFF")         
        time.sleep(1)

    '''try:
        data = ArduinoUnoSerial.readline()
        print data
    except Exception, e:
        print "error open serial port: " + str(e)
        exit()'''

            


