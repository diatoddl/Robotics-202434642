#include <ESP32Servo.h>

#define SERVO_PIN 14
#define POT_PIN 39

Servo myServo;    


void setup() {
    myServo.attach(SERVO_PIN);
    myServo.write(0); //서보 각도
}

void loop() {
     for (int i = 0; i <= 180; i += 2) {
        myServo.write(i);
        delay(15);
    }

    for (int i = 180; i >= 0; i -= 2) {
        myServo.write(i);
        delay(15);
    }
}

