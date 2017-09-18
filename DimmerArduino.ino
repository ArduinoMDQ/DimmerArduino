const int analogInPin = A3;  // Analog input pin that the potentiometer is attached to
const int ledPin = 9; // Analog output pin that the LED is attached to
String inString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int sensorValue;
volatile int contador = 0;   // Somos de lo mas obedientes


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2),ServicioBoton,RISING);
  Serial.println("listo");
}

void loop() {

   sensorValue = analogRead(analogInPin);
   
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
  
   if ( contador > 0){
    Serial.println(contador);
    
    }

}


void ServicioBoton(){
       if ( contador <= 100){
        contador++ ;    
        }
       if ( contador > 100){
        contador=0 ;    
        }
      
        
        
    }

