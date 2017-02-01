/*********************************
 Remote Arduino Serial Port Commander - Slave
 

 Uses an Arduino UNO or Nano

 Connect Vcc to Arduino 5volts
 Connect Gnd to ArduinoGnd
 Connect Rx to Arduino pin 0 (Tx)
 Connect Tx to Arduino pin 1 (Rx)
 Note: disconnect Rx and Tx while uploading the sketch, then connect.

  **********************************/

//
// -------------- Pin variables 
int command;
int pin13;int pin12;int pin11;int pin10;int pin9;int pin8;
int pin7;int pin6;int pin5;int pin4;int pin3;int pin2;
//
// -------------- setup digital pins as OUTPUT or INPUT, 
// OUTPUT = 0 (Zero), INTPUT = 1 (One)
//
int pin2Direction = 0;
int pin3Direction = 0;
int pin4Direction = 0;
int pin5Direction = 1; // INPUT
int pin6Direction = 0; 
int pin7Direction = 1; // INPUT
int pin8Direction = 0;
int pin9Direction = 0;
int pin10Direction = 0;
int pin11Direction = 0;
int pin12Direction = 0;
int pin13Direction = 0;
//
// -------------- General Variables
//
String contactString = ""; // string used to send data to Master
long interval = 500; // interval at which to collect data (milliseconds) = 0.5 second
unsigned long previousMillis = 0; // will store last time data was updated

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);
  //
  // set pin modes
  if(pin2Direction == 0){ pinMode(2, OUTPUT); digitalWrite(2, LOW);}
  else {pinMode(2, INPUT_PULLUP);}
  if(pin3Direction == 0){ pinMode(3, OUTPUT); digitalWrite(3, LOW);}
  else {pinMode(3, INPUT_PULLUP);}
  if(pin4Direction == 0){ pinMode(4, OUTPUT); digitalWrite(4, LOW);}
  else {pinMode(4, INPUT_PULLUP);}
  if(pin5Direction == 0){ pinMode(5, OUTPUT); digitalWrite(5, LOW);}
  else {pinMode(5, INPUT_PULLUP);}
  if(pin6Direction == 0){ pinMode(6, OUTPUT); digitalWrite(6, LOW);}
  else {pinMode(6, INPUT_PULLUP);}
  if(pin7Direction == 0){ pinMode(7, OUTPUT); digitalWrite(7, LOW);}
  else {pinMode(7, INPUT_PULLUP);}
  if(pin8Direction == 0) {pinMode(8, OUTPUT); digitalWrite(8, LOW);}
  else {pinMode(8, INPUT_PULLUP);}
  if(pin9Direction == 0) {pinMode(9, OUTPUT); digitalWrite(9, LOW);}
  else {pinMode(9, INPUT_PULLUP);}
  if(pin10Direction == 0){ pinMode(10, OUTPUT); digitalWrite(10, LOW);}
  else {pinMode(10, INPUT_PULLUP);}
  if(pin11Direction == 0){ pinMode(11, OUTPUT); digitalWrite(11, LOW);}
  else {pinMode(11, INPUT_PULLUP);}
  if(pin12Direction == 0){ pinMode(12, OUTPUT); digitalWrite(12, LOW);}
  else {pinMode(12, INPUT_PULLUP);}
  if(pin13Direction == 0){ pinMode(13, OUTPUT); digitalWrite(13, LOW);}
  else {pinMode(13, INPUT_PULLUP);}
  
}

void loop() {
  //
  // check Timer, send data to Master every 0.5 seconds
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    // save the last time data was sent
    previousMillis = currentMillis; 
    sendDatatoMaster(); // update Master
  }
  //
  if(Serial.available() > 0){ // get data sent from Master
    String input = Serial.readString();
    command = input.toInt(); // convert to an integer
    if(pin13Direction == 0){pin13 = command & 0x0800; if(pin13 != 0){digitalWrite(13, HIGH);} else {digitalWrite(13,LOW);}}
    if(pin12Direction == 0){pin12 = command & 0x0400; if(pin12 != 0){digitalWrite(12, HIGH);} else {digitalWrite(12,LOW);}}
    if(pin11Direction == 0){pin11 = command & 0x0200; if(pin11 != 0){digitalWrite(11, HIGH);} else {digitalWrite(11,LOW);}}
    if(pin10Direction == 0){pin10 = command & 0x0100; if(pin10 != 0){digitalWrite(10, HIGH);} else {digitalWrite(10,LOW);}}
    if(pin9Direction == 0){pin9 = command & 0x0080; if(pin9 != 0){digitalWrite(9, HIGH);} else {digitalWrite(9,LOW);}}
    if(pin8Direction == 0){pin8 = command & 0x0040; if(pin8 != 0){digitalWrite(8, HIGH);} else {digitalWrite(8,LOW);}}
    if(pin7Direction == 0){pin7 = command & 0x0020; if(pin7 != 0){digitalWrite(7, HIGH);} else {digitalWrite(7,LOW);}}
    if(pin6Direction == 0){pin6 = command & 0x0010; if(pin6 != 0){digitalWrite(6, HIGH);} else {digitalWrite(6,LOW);}}
    if(pin5Direction == 0){pin5 = command & 0x0008; if(pin5 != 0){digitalWrite(5, HIGH);} else {digitalWrite(5,LOW);}}
    if(pin4Direction == 0){pin4 = command & 0x0004; if(pin4 != 0){digitalWrite(4, HIGH);} else {digitalWrite(4,LOW);}}
    if(pin3Direction == 0){pin3 = command & 0x0002; if(pin3 != 0){digitalWrite(3, HIGH);} else {digitalWrite(3,LOW);}}
    if(pin2Direction == 0){pin2 = command & 0x0001; if(pin2 != 0){digitalWrite(2, HIGH);} else {digitalWrite(2,LOW);}}
    
  }
  delay(20);

}
//
void sendDatatoMaster(){
  // build a string to send to the master, this includes the state of Digital pins and value of Analog pins
  contactString = "CONTACT," + String(pin2Direction)+ String(pin3Direction) + String(pin4Direction) + String(pin5Direction);
  contactString = contactString + String(pin6Direction)+ String(pin7Direction) + String(pin8Direction) + String(pin9Direction);
  contactString = contactString + String(pin10Direction)+ String(pin11Direction) + String(pin12Direction) + String(pin13Direction) + ",";
  //now add data from digital pins
  contactString = contactString + String(digitalRead(2)) + String(digitalRead(3)) + String(digitalRead(4)) + String(digitalRead(5));
  contactString = contactString + String(digitalRead(6)) + String(digitalRead(7)) + String(digitalRead(8)) + String(digitalRead(9));
  contactString = contactString + String(digitalRead(10)) + String(digitalRead(11)) + String(digitalRead(12)) + String(digitalRead(13));
  // now add data from Analog pins
  contactString = contactString + String(analogRead(A0)) + "," + String(analogRead(A1)) + "," + String(analogRead(A2)) + "," + String(analogRead(A3)) + "," + String(analogRead(A4)) + "," + String(analogRead(A5));
  Serial.println(contactString);   // send to master
  delay(20);
}


