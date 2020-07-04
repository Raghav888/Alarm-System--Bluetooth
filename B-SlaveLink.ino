#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

int state = 0;
int spk = 8;//the pin your led is connected to
int buttonPin = 2;
int buttonState = 0;
int pin= 4;

void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(buttonPin, INPUT);
  pinMode(spk, OUTPUT);
  pinMode(pin,OUTPUT);
  digitalWrite(pin, HIGH );

}

void start() {
  BTserial.write('1');  //sends a 1 through the bluetooth serial link
  delay (5000);
  BTserial.write('0');
  digitalWrite(spk, LOW);
  buttonState = LOW;

}

void start1() {
  digitalWrite(spk, HIGH); // LED ON
  delay(5000);
  state = 0;
  digitalWrite(spk, LOW); // LED ON
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    buttonState = LOW;
    delay(2000);
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      start();
    }
  }

  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read(); // Reads the data from the serial port

    if (state == '1') {
        start1();
    }
  }
}
