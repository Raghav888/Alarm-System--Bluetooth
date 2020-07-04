#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int state = 0;
const int ledPin = 13;
int spk = 8;//the pin your led is connected to
int buttonPin = 2;
int buttonState = LOW ;


void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(buttonPin, INPUT);
  pinMode(spk, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void start() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(spk, HIGH);
  BTserial.write('1');  //sends a 1 through the bluetooth serial link
  delay (5000);
  BTserial.write('0');
  digitalWrite(ledPin, LOW);
  digitalWrite(spk, LOW);
  buttonState = LOW;

}

void start1() {
  digitalWrite(spk, HIGH); // LED ON
  delay(5000);
  state = 0;
  digitalWrite(spk, LOW);
  buttonState = LOW;    // LED ON
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    buttonState = LOW;
    delay(1000);
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      buttonState = LOW;
      delay(1000);
      buttonState = digitalRead(buttonPin);
      if (buttonState == HIGH) {
        start();
      }
    }
  }

  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read(); // Reads the data from the serial port

    if (state == '1') {
      start1();
    }
  }
}
