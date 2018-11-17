byte incoming[4];
int int_incoming;
byte split_int_or_float[4];;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  //Serial.println("Ready");
}

void loop() {
  if(Serial.available()>=4) {
    
    //Method 0: Reading and sending back bytes 
    /*for (int i = 0; i < 4; i++) {
      incoming[i] = Serial.read();
    }
    Serial.println("----------------------");
    Serial.println(incoming[0]);
    Serial.println(incoming[1]);
    Serial.println(incoming[2]);
    Serial.println(incoming[3]);*/
    /*If we wrote a pack of ints, the most sig bits of each number
     * are stored in incoming[0] and least sig bits 
     * are in incoming[3]
     * If we wrote a pack of 4 bytes they're stored in 
     * incoming[0-3] in the order they came in */
     

    //Method 1: Reading and sending back ints, 
    /*int_incoming = Serial.read();
    int_incoming = int_incoming*256 + Serial.read();
    int_incoming = int_incoming*256 + Serial.read();
    int_incoming = int_incoming*256 + Serial.read();
    Serial.println(int_incoming);*/


    //Method 2: Reading and sending back ints or floats, 4 bytes at a time using struct.unpack in python. This might be in direction of what we want
    /*for (int i = 0; i < 4; i++){
      split_int_or_float[i] = Serial.read(); //we need to reverse the order because of the order python is reading off of serial 
    }*/
    Serial.readBytes(split_int_or_float, 4); //The cleaner version of above
    Serial.write(split_int_or_float, 4);
  }
}
