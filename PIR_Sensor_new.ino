int ledPin = 7;                // choose the pin for the LED
int inputPin2 = 4;               // choose the input pin (for PIR sensor)
int inputPin3 = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val2 = 0;                    // variable for reading the pin status
int val3 = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin2, INPUT);     // declare sensor as input
  pinMode(inputPin3, INPUT);     // declare sensor as input  
 
  Serial.begin(9600);
  delay(30000);
}

void pir1sta()
{
   digitalWrite(ledPin, HIGH); 
     delay(2000);
     digitalWrite(ledPin, LOW); // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("pin 2 Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
    val2 =LOW;
}
void pir2sta()
{
  digitalWrite(ledPin, HIGH); 
  delay(5000);
     digitalWrite(ledPin, LOW);// turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("pin 3 Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    } 
val3=LOW;
}


 void loop(){
 
  val2 = digitalRead(inputPin2);  // read input value
    // read input value
  if (val2 == HIGH) {            // check if the input is HIGH
    pir1sta();
  } 
  val3 = digitalRead(inputPin3); 
  if (val3 == HIGH) {            // check if the input is HIGH
   pir2sta();
  }  
 
 
}
