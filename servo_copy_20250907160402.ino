#include <Servo.h>

const int IR_PIN = 2;      // đầu ra digital của IR
const int SERVO_PIN = 6;   // tín hiệu servo

// Nếu cảm biến cho mức LOW khi có vật cản (rất thường gặp) thì để true
const bool IR_ACTIVE_LOW = true;

const int OPEN_ANGLE  = 90;  // góc mở barrier
const int CLOSE_ANGLE = 0;   // góc đóng barrier

Servo gate;

void setup() {
  pinMode(IR_PIN, INPUT_PULLUP);
  gate.attach(SERVO_PIN);
  gate.write(CLOSE_ANGLE);   // mặc định đóng
}

void loop() {
  bool blocked = (digitalRead(IR_PIN) == (IR_ACTIVE_LOW ? HIGH : LOW));
  gate.write(blocked ? OPEN_ANGLE : CLOSE_ANGLE);
  delay(1020); // nhỏ chống rung, đủ dùng
}