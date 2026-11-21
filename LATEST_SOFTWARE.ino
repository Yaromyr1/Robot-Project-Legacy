

// SOFTWARE FOR A robot DEVELOPED BY YAROMYR
//             2021-2024

// IF USED, PLEASE LEAVE CREDIT IN THE CODE.

#include <Servo.h>
char t;
int state = 0;
int flag = 0;

#define leftmtr 13          // left motor
#define rightmtr 11        // right motor
#define leftmtrReverse 9  // left motor back
#define rightmtrReverse 8 // right motor back
#define ledindicator 10    // led

void setup() {
  // Bluetooth modual connects to RX and TX pins
  pinMode(10, OUTPUT);  // led
  pinMode(13, OUTPUT);   // left motor                    
  pinMode(11, OUTPUT);   // right motor
  pinMode(9, OUTPUT);  // left motor back                 
  pinMode(8, OUTPUT);   // right motor back
  Serial.begin(9600);   // Default connection rate for my BT module

  digitalWrite(ledindicator, HIGH);  // blink 1
  delay(400);
  digitalWrite(ledindicator, LOW);
  delay(400);
  digitalWrite(ledindicator, HIGH);  // blink 2
  delay(400);
  digitalWrite(ledindicator, LOW);
  delay(400);
  digitalWrite(ledindicator, HIGH);  // blink 3
  delay(400);
  digitalWrite(ledindicator, LOW);
  delay(5000);         // STARTUP TIME
  Serial.println(" ");  // space
  Serial.println("SYSTEM (ON)");
  delay(500);
  Serial.println("DEVICE CONNECTED");
  delay(1050);
  Serial.print("LOADING");
  delay(1105);
  Serial.print(".");
  delay(1105);
  Serial.print(".");
  delay(1105);
  Serial.print(".");
  delay(1105);
  Serial.println("READY");
  delay(1000);
  Serial.println(" ");
  Serial.println("DIAGNOSTICS COMPLETE");  // time to connect to robot (21.6 seconds boot time)
  Serial.println(" ");
  delay(500);
  Serial.print("Motors STATUS:");
  delay(1200);
  Serial.println(" READY");
  delay(1000);
  Serial.print("Sensor STATUS:");
  delay(1000);
  Serial.println(" READY");
  delay(1000);
  Serial.print("Controls STATUS:");
  delay(1000);
  Serial.println(" READY");
  delay(1000);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("READY TO RECIEVE INPUTS");
  Serial.println(" ");
  digitalWrite(ledindicator, HIGH);
  delay(500);
}
void loop() {

  if (Serial.available()) {
    t = Serial.read();  // Bluetooth setup code
    Serial.println(t);
  }

  else if (t == 'F') {                //forward (motors rotate in the forward direction)
    digitalWrite(ledindicator, LOW);  // blink
    Serial.println("_MOTORS ENGAGED moving forward_");
    digitalWrite(leftmtrReverse, LOW);
    digitalWrite(rightmtrReverse, LOW);
    // SAFEGUARDS end here
    digitalWrite(leftmtr, HIGH);
    digitalWrite(rightmtr, HIGH);
    delay(10);
    digitalWrite(ledindicator, HIGH);
  } 
  
  else if (t == 'B') {              //reverse (motors rotate in the reverse direction)
    digitalWrite(ledindicator, LOW);  // blink
    Serial.println("_MOTORS ENGAGED moving in reverse_");
    digitalWrite(leftmtr, LOW);
    digitalWrite(rightmtr, LOW);
    // SAFEGUARDS end here
    digitalWrite(leftmtrReverse, HIGH);
    digitalWrite(rightmtrReverse, HIGH);
    delay(10);
    digitalWrite(ledindicator, HIGH);
  }

  else if (t == 'L') {                //turn right (right side motor rotates in the forward direction,  left side motor rotates in reverse)
    digitalWrite(ledindicator, LOW);  // blink
    Serial.println("_TURNING LEFT_");
    digitalWrite(rightmtrReverse, LOW);
    digitalWrite(leftmtr, LOW);
    // SAFEGUARDS end here
    digitalWrite(leftmtrReverse, HIGH);
    digitalWrite(rightmtr, HIGH);
    delay(10);
    digitalWrite(ledindicator, HIGH);
  }

  else if (t == 'R') {                //turn left (left side motor rotates in the forward direction, right side motor rotates in reverse)
    digitalWrite(ledindicator, LOW);  // blink
    Serial.println("_TURNING RIGHT_");
    digitalWrite(leftmtrReverse, LOW);
    digitalWrite(rightmtr, LOW);
    // SAFEGUARDS end here
    digitalWrite(leftmtr, HIGH);
    digitalWrite(rightmtrReverse, HIGH);
    delay(10);
    digitalWrite(ledindicator, HIGH);
  }

  else if (t == 'S') {                //STOP (all motors stop)
    digitalWrite(ledindicator, LOW);  // blink
    Serial.println("_MOTORS DISENGAGED_");
    digitalWrite(leftmtr, LOW);
    digitalWrite(rightmtr, LOW);
    digitalWrite(leftmtrReverse, LOW);
    digitalWrite(rightmtrReverse, LOW);
    delay(10);
    digitalWrite(ledindicator, HIGH);
  }
}

// Heating up the motors improves their efficiency. Also any issues with the gears can be fixed with motor heating.
