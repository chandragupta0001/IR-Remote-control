/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright Chandragupta
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 14;
int c=0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(4,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value,DEC);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  if (((results.value)==33441975) &&( c==0)) {
 Serial.println("YES");
results.value=00000000;
digitalWrite(4,HIGH);
c=1;
  }
   if (((results.value)==33441975) &&( c==1)) {
 Serial.println("YES");
results.value=00000000;
digitalWrite(4,LOW);
c=0;}
}
