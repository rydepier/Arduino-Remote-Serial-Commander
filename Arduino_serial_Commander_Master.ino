/*********************************
 Remote Arduino Serial Port Commander - Master
 send/receive from a PC USB port

 Uses an Arduino Uno or Nano

 Connect Vcc to Arduino 5volts
 Connect Gnd to ArduinoGnd
 Connect Rx to Arduino pin 3 (Tx)
 Connect Tx to Arduino pin 2 (Rx)
 Connect SET to Arduino pin 4 (Take LOW to send AT Commands)

 REALTERM can be used to communicate with an Arduino fitted with another HC-12

 To switch HC-12 to AT Mode, send ATSEND from PC, ensure CRLF is switched ON
 To reset to Normal mode, send ATEND

 **********************************/

#include <SoftwareSerial.h>
#define ATpin 4 // used to switch to AT mode
#define LEDpin 13
SoftwareSerial mySerial(2, 3); //RX, TX

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);
  pinMode(ATpin, OUTPUT);
  digitalWrite(ATpin, HIGH); // normal mode
  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin, LOW);
  mySerial.begin(9600);
  mySerial.setTimeout(20);
  // show this is the master by flashing 3 times
  for(int i = 1; i < 4; i++){
    digitalWrite(LEDpin, HIGH);
    delay(500);
    digitalWrite(LEDpin, LOW);
    delay(500);
  }
}

void loop() {
  if(Serial.available() > 0){ // Read from serial input (from PC) and send over HC-12
    String input = Serial.readString();
    //Serial.println(input); // for debugging
    if(input.startsWith("ATEND")){
      digitalWrite(ATpin, HIGH); // exit AT Mode
      digitalWrite(LEDpin, LOW);
    }
    else if(input.startsWith("ATSEND")){
      digitalWrite(ATpin, LOW); // go into AT Mode
      digitalWrite(LEDpin, HIGH);
    }
    else{
      mySerial.println(input); 
    }      
  }
  if(mySerial.available() > 1){ // Read from HC-12 and send to PC
    String input = mySerial.readString();
    Serial.println(input);   
  }
  delay(20);
}
