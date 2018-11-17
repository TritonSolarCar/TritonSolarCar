byte myBytes[] = {3,4,6,8,10};

int myInts[] = {3,4,6,8,10};
byte ints_to_bytes[sizeof(myInts)]; //sizeof() returns the number of bytes something has, not elements

float myFloats[] = {2.5, 4, 6.6, 8.75, 10};
byte floats_to_bytes[sizeof(myFloats)];
//use this to divide up individual floats into their component bytes
typedef union{
 float number;
 unsigned char bytes[4];
} float_union;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  
  //Attempt 1: with bytes
  //Serial.write(myBytes, 5); 

  //Attempt 2: with ints. NOTE: Ints in most arduino boards are stored in 2 bytes, not 4!
  /*int x;
  int int_size = sizeof(int);
  int number_elems = sizeof(myInts)/int_size; //sizeof() returns the number of bytes 
  for (int i = 0; i < number_elems; i++){
    x = myInts[i];
    ints_to_bytes[i*int_size+1] = x >> 8;
    ints_to_bytes[i*int_size] = x;
  }
  Serial.write(ints_to_bytes, sizeof(ints_to_bytes));*/

  //Attempt 3: with floats. NOTE: floats are stored in 4 bytes
  float_union x;
  int number_elems = sizeof(myFloats)/4; //sizeof() returns the number of bytes 
  for (int i = 0; i < number_elems; i++){
    x.number = myFloats[i];
    floats_to_bytes[i*4+3] = x.bytes[3];
    floats_to_bytes[i*4+2] = x.bytes[2];
    floats_to_bytes[i*4+1] = x.bytes[1];
    floats_to_bytes[i*4] = x.bytes[0];
  }
  Serial.write(floats_to_bytes, sizeof(floats_to_bytes));
}

void loop() {
}
