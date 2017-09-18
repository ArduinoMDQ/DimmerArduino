#include <TimerOne.h>

const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to
const int ledPin = 9; // Analog output pin that the LED is attached to
const int controlDrimer = 3;
String inString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int sensorValue;
volatile int contador = 0;   // Somos de lo mas obedientes
int t=0;


void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(controlDrimer, OUTPUT);
  
  digitalWrite(controlDrimer,LOW);
  attachInterrupt(digitalPinToInterrupt(2),zeroCross,FALLING );
  
  digitalWrite(ledPin,HIGH);
  delay(100);
  digitalWrite(ledPin,LOW);
  Serial.println("Inicializado");

}

void loop() {

  // sensorValue = analogRead(analogInPin);
   
//  analogWrite(ledPin,sensorValue/4);
   
  while (Serial.available() > 0) {
    
    int inChar = Serial.read();
   
    int valor=0;
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      Serial.println(inString.toInt());
      valor=inString.toInt();
      Serial.print("valor: ");
      Serial.println(valor);
      // clear the string for new input:
      inString = "";
      analogWrite(ledPin,valor);
    }
  }

}

void zeroCross(){
  
 Timer1.initialize(5000);
 Timer1.attachInterrupt(Dimmer); 
 digitalWrite(controlDrimer,LOW);
}

void Dimmer(){
  digitalWrite(controlDrimer,HIGH);
 
}

