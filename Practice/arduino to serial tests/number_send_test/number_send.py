import serial                                       #Serial imported for Serial communication
import time                                         #Required to use delay functions   
import struct                                       #nterpret strings as packed binary data

ser = serial.Serial(
    port='COM3',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1 
)
time.sleep(2) 
#ser.write(struct.pack('>BBBB',75,10,220,30)) #send 4 unsigned bytes (for method 0)
#ser.write(struct.pack('>iiii',75,10,330,30)) #send 4 ints 
ser.write(struct.pack('>ffff',75,10.7,220,30)) #send 4 floats (method 2)
#ser.write(struct.pack('>iiii',73,74,75,76)) #ascii values for I,J,K, and L sent in int form

while True:
    #for the first two methods in the arduino sketch
    #Be careful when using readline(). Do specify a timeout when opening 
    #the serial port otherwise it could block forever if no newline character is received.
    '''data =  ser.readline() 
    print data'''

    #for the third method in the arduino sketch. This actually correctly obtains int values
    '''if (ser.inWaiting() > 3):   #make sure we have 4 bytes available to read 
        byteString = ser.read(4)
        #printing byteString would print the ascii value 
        result = struct.unpack(">I", byteString)[0] #the '>' tells python that the bytes are stored in big endian order
        print result'''

    #for floats in method 2 in arduino sketch, for floats
    if (ser.inWaiting() > 3):   #make sure we have 4 bytes available to read 
        byteString = ser.read(4)
        #printing byteString would print the ascii value 
        result = struct.unpack(">f", byteString)[0]
        print result
        #interestingly, if we sent the pack of ints from python to arduino instead,
        #this would print in floating point representation 

    time.sleep(.5)
    
    