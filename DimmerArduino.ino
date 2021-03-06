#include <TimerOne.h>

unsigned long tiempo;
const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to
const int ledPin = 9; // Analog output pin that the LED is attached to
const int controlDrimer = 3;
String inString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int sensorValue;
volatile int contador = 0;   // Somos de lo mas obedientes
int t=0;
volatile int valor=9;

void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(controlDrimer, OUTPUT);
  digitalWrite(controlDrimer,LOW);
   
  noInterrupts();   
  attachInterrupt(digitalPinToInterrupt(2),zeroCross,RISING );
  Serial.print("9");
  interrupts(); 
}

void loop() {

  // sensorValue = analogRead(analogInPin);
   
//  analogWrite(ledPin,sensorValue/4);
   
  while (Serial.available() > 0) {
    
    int inChar = Serial.read();
      valor="";
    
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
      //valor=inString.toInt();   
    }
    if (inChar == '\r') {
    //  Serial.print("Value:");
    //  Serial.println(inString.toInt());
    //  valor=inString.toInt();    
    //  Serial.print("valor: ");
    //  Serial.print(valor);// Serial.print("\r");
    //  clear the string for new input:
        valor=inString.toInt();   
        Serial.print(valor);Serial.print("\r"); 
        inString = "";
   
    //  analogWrite(ledPin,valor);
   }
  }

}

void zeroCross(){
 digitalWrite(controlDrimer,LOW);
 noInterrupts();
 Timer1.initialize(10000 -(valor*1000));
 Timer1.attachInterrupt(Dimmer);
 interrupts();
}

void Dimmer(){
  Timer1.stop();
  digitalWrite(controlDrimer,HIGH);
  }

