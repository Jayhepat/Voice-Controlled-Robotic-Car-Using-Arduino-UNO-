#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
VR myVR(2, 3);


#define G (0)
#define B (1)
#define L (2)
#define R (3)

int ret;
uint8_t buf[64];

#define enA 4
#define L1 8
#define L2 9
#define R1 10
#define R2 11
#define enB 5


void setup() {
  myVR.begin(9600);
  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  analogWrite(enA,0);
  analogWrite(enB,0);


  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1)
    {
      delay(100);
    }
  }
  if (myVR.load((uint8_t)G) >= 0) {
    Serial.println("GO loaded");
  }

  if (myVR.load((uint8_t)B) >= 0) {
    Serial.println("BACK loaded");
  }
  if (myVR.load((uint8_t)L) >= 0) {
    Serial.println("LEFT loaded");
  }

  if (myVR.load((uint8_t)R) >= 0) {
    Serial.println("RIGHT loaded");
  }
}

void loop() {
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case G:
        /** GO FORWARD */
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1,  LOW);
        digitalWrite(L2, HIGH);
        digitalWrite(R1, HIGH);
        digitalWrite(R2, LOW);
        delay(500);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        digitalWrite(R1, LOW);
        digitalWrite(R2, LOW);        
        break;
      case B:
        /** GO BACK*/
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
        digitalWrite(R1, LOW);
        digitalWrite(R2, HIGH);
        delay(500);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        digitalWrite(R1, LOW);
        digitalWrite(R2, LOW);
        break;
      case L:
        /** TURN LEFT*/
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, LOW);
        digitalWrite(L2, HIGH);
        digitalWrite(R1, LOW);
        digitalWrite(R2, HIGH);
        delay(200);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        digitalWrite(R1, LOW);
        digitalWrite(R2, LOW);
        break;
       case R:
        /**TURN RIGHT*/
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
        digitalWrite(R1, HIGH);
        digitalWrite(R2, LOW);
        delay(200);
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        digitalWrite(R1, LOW);
        digitalWrite(R2, LOW);
        break;
      default:
        Serial.println("undefined");
        break;
    }
  }
}
