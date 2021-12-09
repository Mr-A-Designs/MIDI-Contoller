/*
 4 channels MIDI video switcher for use with Partical Photon
*/

const int numReadings1 = 10;
const int numReadings2 = 10;
const int numReadings3 = 10;
const int numReadings4 = 10;

int readings1[numReadings1];      // the readings from the analog input
int readIndex1 = 0;              // the index of the current reading
int total1 = 0;                  // the running total
int average1 = 0;                // the average

int inputPin1 = A0;

int readings2[numReadings2];      // the readings from the analog input
int readIndex2 = 0;              // the index of the current reading
int total2 = 0;                  // the running total
int average2 = 0;                // the average

int inputPin2 = A1;

int readings3[numReadings3];      // the readings from the analog input
int readIndex3 = 0;              // the index of the current reading
int total3 = 0;                  // the running total
int average3 = 0;                // the average

int inputPin3 = A2;

int readings4[numReadings4];      // the readings from the analog input
int readIndex4 = 0;              // the index of the current reading
int total4 = 0;                  // the running total
int average4 = 0;                // the average

int inputPin4 = A3;

int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 4 pots.
int lastVal = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;

const int buttonPin1 = D0;     //PROGRAM 1
const int buttonPin2 = D1;     //PROGRAM 2
const int buttonPin3 = D2;     //PROGRAM 3
const int buttonPin4 = D3;     //PROGRAM 4
const int buttonPin5 = D4;     //PREVIEW 1
const int buttonPin6 = D5;     //PREVIEW 2
const int buttonPin7 = D6;     //PREVIEW 3
const int buttonPin8 = D7;     //PREVIEW 4
const int buttonPin9 = A4;     //PREVIEW 1
const int buttonPin10 = A5;     //PREVIEW 2
const int buttonPin11 = A6;     //PREVIEW 3
const int buttonPin12 = A7;     //PREVIEW 4

//initialize variables
int buttonState1 = 1;         
int buttonState2 = 1;
int buttonState3 = 1;
int buttonState4 = 1;
int buttonState5 = 1;         
int buttonState6 = 1;
int buttonState7 = 1;
int buttonState8 = 1;
int buttonState9 = 1;         
int buttonState10 = 1;
int buttonState11 = 1;
int buttonState12 = 1;


void setup() {
  Serial.begin(115200); //Set MIDI baud rate to communication
  //setup pins mode on Arduino board
  pinMode(inputPin1, INPUT); //Pot 1
  pinMode(inputPin2, INPUT); //Pot 2
  pinMode(inputPin3, INPUT); //Pot 3
  pinMode(inputPin4, INPUT); //Pot 4
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);
  pinMode(buttonPin11, INPUT_PULLUP);
  pinMode(buttonPin12, INPUT_PULLUP);
  for (int thisReading1 = 0; thisReading1 < numReadings1; thisReading1++) {
    readings1[thisReading1] = 0;
  }
  for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++) {
    readings2[thisReading2] = 0;
  }
  for (int thisReading3 = 0; thisReading3 < numReadings3; thisReading3++) {
    readings3[thisReading3] = 0;
  }
  for (int thisReading4 = 0; thisReading4 < numReadings4; thisReading4++) {
    readings4[thisReading4] = 0;
  }
}
//send note to serial port
void noteOn(byte channel, byte pitch, byte velocity) {
  Serial.write(channel);
  Serial.write(pitch);
  Serial.write(velocity);
}
void noteOff(byte channel, byte pitch, byte velocity) {
  Serial.write(0x80);
  Serial.write(channel);
  Serial.write(pitch);
  Serial.write(velocity);
}
void MIDImessage(byte channel, byte controller, byte value) //pass values out through standard Midi Command
{
   Serial.write(channel);
   Serial.write(controller);
   Serial.write(value);
}
//Main:
void loop() {
  //1
  // subtract the last reading:
  total1 = total1 - readings1[readIndex1];
  // read from the sensor:
  readings1[readIndex1] = analogRead(inputPin1);
  // add the reading to the total:
  total1 = total1 + readings1[readIndex1];
  // advance to the next position in the array:
  readIndex1 = readIndex1 + 1;

  // if we're at the end of the array...
  if (readIndex1 >= numReadings1) {
    // ...wrap around to the beginning:
    readIndex1 = 0;
  }

  // calculate the average:
  average1 = total1 / numReadings1;
  // send it to the computer as ASCII digits

  
  //2
  // subtract the last reading:
  total2 = total2 - readings2[readIndex2];
  // read from the sensor:
  readings2[readIndex2] = analogRead(inputPin2);
  // add the reading to the total:
  total2 = total2 + readings2[readIndex2];
  // advance to the next position in the array:
  readIndex2 = readIndex2 + 1;

  // if we're at the end of the array...
  if (readIndex2 >= numReadings2) {
    // ...wrap around to the beginning:
    readIndex2 = 0;
  }

  // calculate the average:
  average2 = total2 / numReadings2;
  // send it to the computer as ASCII digits

  
  //3
  // subtract the last reading:
  total3 = total3 - readings3[readIndex3];
  // read from the sensor:
  readings3[readIndex3] = analogRead(inputPin3);
  // add the reading to the total:
  total3 = total3 + readings3[readIndex3];
  // advance to the next position in the array:
  readIndex3 = readIndex3 + 1;

  // if we're at the end of the array...
  if (readIndex3 >= numReadings3) {
    // ...wrap around to the beginning:
    readIndex3 = 0;
  }

  // calculate the average:
  average3 = total3 / numReadings3;
  // send it to the computer as ASCII digits

  //4
  // subtract the last reading:
  total4 = total4 - readings4[readIndex4];
  // read from the sensor:
  readings4[readIndex4] = analogRead(inputPin4);
  // add the reading to the total:
  total4 = total4 + readings4[readIndex4];
  // advance to the next position in the array:
  readIndex4 = readIndex4 + 1;

  // if we're at the end of the array...
  if (readIndex4 >= numReadings4) {
    // ...wrap around to the beginning:
    readIndex4 = 0;
  }

  // calculate the average:
  average4 = total4 / numReadings4;
  // send it to the computer as ASCII digits

    
  //reading buttons states
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);
  buttonState10 = digitalRead(buttonPin10);
  buttonState11 = digitalRead(buttonPin11);
  buttonState12 = digitalRead(buttonPin12);

  //discovering button states
  if (buttonState1 == 0) {
    noteOn(0x90, 60, 127); //send midi as note on
  } else {
     
  }
  if (buttonState2 == 0) {
    noteOn(0x91, 60, 127); //send midi as note on  
  } else {
      
  }
  if (buttonState3 == 0) {
    noteOn(0x92, 60, 127); //send midi as note on   
  } else {
      
  }
  if (buttonState4 == 0) {
    noteOn(0x93, 60, 127); //send midi as note on   
  } else {
      
  }
  //------------------------------------------
  if (buttonState5 == 0) {
    noteOn(0x94, 60, 127); //send midi  as note on  
  } else {
      
  }
  if (buttonState6 == 0) {
    noteOn(0x95, 60, 127); //send midi as note on    
  } else {
      
  }
  if (buttonState7 == 0) {
    noteOn(0x96, 60, 127); //send midi as note on    
  } else {
     
  }
  if (buttonState8 == 0) {
    noteOn(0x97, 60, 127); //send midi as note on   
  } else {
      
  }
  //------------------------------------------
  if (buttonState9 == 0) {
    noteOn(0x98, 60, 127); //send midi  as note on  
  } else {
      
  }
  if (buttonState10 == 0) {
    noteOn(0x99, 60, 127); //send midi as note on    
  } else {
      
  }
  if (buttonState11 == 0) {
    noteOn(0x9A, 60, 127); //send midi as note on    
  } else {
      
  }
  if (buttonState12 == 0) {
    noteOn(0x9B, 60, 127); //send midi as note on   
  } else {
      
  }
  //-----------------------------------------
  //discovering potentiometer value 
{
   val = (average1)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(0xB0,1,val);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal = val; if (val>127, val=127);

   val2 = (average2)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val2 != lastVal2) 
   {
   MIDImessage(0xB1,2,val2);}         // 176 = CC command, 2 = Which Control, val = value read from Potentionmeter 2
   lastVal2 = val2; if (val2>127, val2=127);
   
   val3 = (average3)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val3 != lastVal3) 
   {
   MIDImessage(0xB2,4,val3);}         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
   lastVal3 = val3; if (val3>127, val3=127);
   
   val4 = (average4)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val4 != lastVal4) 
   {
   MIDImessage(0xB3,7,val4);}         // 176 = CC command, 4 = Which Control, val = value read from Potentionmeter 4
   lastVal4 = val4; if (val4>127, val4=127);
delay(10); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.
}
}
