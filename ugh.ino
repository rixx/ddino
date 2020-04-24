#include <CapacitiveSensor.h>

CapacitiveSensor   cs_up = CapacitiveSensor(13, 8);           // YELLOW IS UP
CapacitiveSensor   cs_down = CapacitiveSensor(13, 9);       // WHITE IS DOWN
CapacitiveSensor   cs_left = CapacitiveSensor(13, 10);       // RED IS LEFT
CapacitiveSensor   cs_right = CapacitiveSensor(13, 11);        // GREEN IS RIGHT

int threshold = 1000; // the minimum value for turning the LED on
int ledPin = 3;

int upStatus=0;
int upStatusPrev=0;
int leftStatus=0;
int leftStatusPrev=0;
int downStatus=0;
int downStatusPrev=0;
int rightStatus=0;
int rightStatusPrev=0;

void setup() {
    // turn off autocalibrate on channel 1. 
    cs_up.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs_down.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs_left.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs_right.set_CS_AutocaL_Millis(0xFFFFFFFF);

    delay(3000);  // boot time
    Serial.begin(9600);

    /* pinMode(ledPin, OUTPUT); */
    /* digitalWrite(ledPin, LOW); */
}
    
void loop() {

    long upSensor = cs_up.capacitiveSensor(30);
    long downSensor = cs_down.capacitiveSensor(30);
    long leftSensor = cs_left.capacitiveSensor(30);
    long rightSensor = cs_right.capacitiveSensor(30);

    long upStatus = upSensor > threshold ? 1 : 0;
    long downStatus = downSensor > threshold ? 1 : 0;
    long leftStatus = leftSensor > threshold ? 1 : 0;
    long rightStatus = rightSensor > threshold ? 1 : 0;

    /* Serial.print("up\tdown\tleft\tright\n"); */
    /* Serial.print(upSensor); */
    /* Serial.print("\t"); */
    /* Serial.print(downSensor); */
    /* Serial.print("\t"); */
    /* Serial.print(leftSensor); */
    /* Serial.print("\t"); */
    /* Serial.print(rightSensor); */
    /* Serial.print("\n"); */

    // UP ARROW
    if (upStatus != upStatusPrev) {
      if (upStatus == 1) {
          Serial.print("up-start\n");
      } else {
          Serial.print("up-end\n");
      }
      upStatusPrev = upStatus;
    }

    // LEFT ARROW PRESSED
    if (leftStatus != leftStatusPrev) {
      if (leftStatus == 1) {
          Serial.print("left-start\n");
      } else {
          Serial.print("left-end\n");
      }
      leftStatusPrev = leftStatus;
    }
    
    // DOWN ARROW
    if (downStatus != downStatusPrev) {
      if (downStatus == 1) {
          Serial.print("down-start\n");
      } else {
          Serial.print("down-end\n");
      }
      downStatusPrev = downStatus;
    }
    
    // RIGHT ARROW
    if (rightStatus != rightStatusPrev) {
      if (rightStatus == 1) {
          Serial.print("right-start\n");
      } else {
          Serial.print("right-end\n");
      }
      rightStatusPrev = rightStatus;
    }

    delay(20);
}
