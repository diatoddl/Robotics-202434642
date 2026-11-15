#include <ESP32Servo.h>

#define SERVO_PIN 14
#define POT_PIN 39

Servo myServo;


void setup() {
    myServo.attach(SERVO_PIN);
    myServo.write(0); //서보 각도
}

void loop() {

    int value = analogRead(POT_PIN);

    int angle = map(value, 0, 4095, 0, 180);

    myServo.write(angle);
}
