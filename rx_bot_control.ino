#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

// Motor Pins
int enA = 5, in1 = 8, in2 = 9;
int enB = 6, in3 = 10, in4 = 7;

void setup() {
  Serial.begin(9600);
  if (!driver.init()) {
    Serial.println("RF RX init failed");
  }

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    char command = (char)buf[0];
    Serial.print("Received: "); Serial.println(command);

    switch (command) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotors(); break;
    }
  }
}

void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void moveBackward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void turnLeft() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  analogWrite(enB, 0);
}

void turnRight() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void stopMotors() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
