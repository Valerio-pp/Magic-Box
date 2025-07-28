// Valerio
// 28.07.2025
// Magic Box

#include <Arduino.h>
#include <Servo.h>

Servo servo;

const int SERVO_PIN = 9;
const int BUTTON_PIN = 8;
const int LED_PIN = 7;

int angleClosed = 15;
int angleOpen = 90;
int speed = 15;

bool isOpen = false;
bool buttonLocked = false;

void setup() {
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  servo.write(angleClosed);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && !buttonLocked) {
    buttonLocked = true;
    delay(200); // debounce

    if (!isOpen) {
      delay(2000); // delay before opening
      digitalWrite(LED_PIN, HIGH);
      moveServo(angleClosed, angleOpen);
      isOpen = true;
    } else {
      moveServo(angleOpen, angleClosed);
      digitalWrite(LED_PIN, LOW);
      isOpen = false;
    }
  }

  if (digitalRead(BUTTON_PIN) == HIGH) {
    buttonLocked = false;
  }
}

void moveServo(int from, int to) {
  int step = (from < to) ? 1 : -1;
  for (int pos = from; pos != to + step; pos += step) {
    servo.write(pos);
    delay(speed);
  }
}
