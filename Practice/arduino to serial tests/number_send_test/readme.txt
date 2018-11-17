Testing of sending multiple ints from python to arduino using struct.pack(...)
Arduino sketch reads these numbers and sends back their bytes for python script to print
Run with python number_send.py

/*incoming[i] = Serial.parseInt(); 
       * better not to use this. 
       * Reason: Those are "blocking" functions with a default timeout of one second. This means: If there is not 
         data arriving the moment you are calling the funtion, that function has the same effect as "delay(1000) in your code. */


useful documentation:
python structs: https://docs.python.org/2/library/struct.html