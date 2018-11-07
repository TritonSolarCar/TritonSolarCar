int buttonPin = 9; // the number of the pushbutton pin
int ledPin = 8; // the number of the LED pin
// variables will change:
int buttonState = LOW; // variable for reading the pushbutton status
int ledState = LOW; // variable to store the LED state: HIGH = on, LOW = off
void setup() {
pinMode(buttonPin, INPUT);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}
void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead( buttonPin );
  // check if the pushbutton is pressed.
  if (buttonState == HIGH && ledState == LOW) {
  // turn LED on:
  digitalWrite(ledPin , HIGH );
   ledState = HIGH;
   Serial.print(buttonState);
  }
  else if ( ledState == HIGH) {
  // turn LED off:
  digitalWrite(ledPin, LOW);
   ledState = LOW;
  }
   delay(100); // delay in order to give some time to read the button press
   //you can change this value and observe the difference
}
