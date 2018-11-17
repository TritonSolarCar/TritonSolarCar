int userdata;
int LED = 13;
void setup() {
  Serial.begin(9600); //initialize serial COM at 9600 baudrate
  pinMode(LED_BUILTIN, OUTPUT); //make the LED pin (13) as output
  digitalWrite (LED_BUILTIN, LOW);
  Serial.println("Hi!, I am Arduino");
  Serial.write("Hello. Would you like to go out for some ice-cream?\n");
}

void loop() {
  while (Serial.available())    //whatever the data that is coming in serially and assigning the value to the variable “data”
  { 
    userdata = Serial.read();
  }
  
  if (userdata == '1')
  
  digitalWrite (LED, HIGH);                  //Turn On the Led
  
  else if (userdata == '0')
  
  digitalWrite (LED, LOW);                  //Turn OFF the Led
}
