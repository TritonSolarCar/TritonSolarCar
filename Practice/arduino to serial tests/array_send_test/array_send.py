import serial                                       #Serial imported for Serial communication
import time                                         #Required to use delay functions   
import struct
ser = serial.Serial(
    port='COM3',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1 
)
time.sleep(2)

while(1):
    #for attempt 1 with bytes
    '''if ser.inWaiting()>=5:
        byteString = ser.read(5)
        result = struct.unpack("bbbbb", byteString) #unpack a tuple with 5 bytes
        print result'''

    '''if ser.inWaiting()>=10:                          
        byteString = ser.read(10)                    #read 10 bytes (5 shorts)
        result = struct.unpack("<hhhhh", byteString) #unpack a tuple with 5 shorts
        print result'''

    if ser.inWaiting()>=20:                          
        byteString = ser.read(20)                    #read 20 bytes (5 floats)
        result = struct.unpack("<fffff", byteString) #unpack a tuple with 5 floats
        print result
    
    time.sleep(.5)