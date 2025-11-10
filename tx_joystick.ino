#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

// Joystick pins
int joyX = A0;
int joyY = A1;

void setup() {
  Serial.begin(9600);
  if (!driver.init()) {
    Serial.println("RF TX init failed");
  }
}

void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  char command = 'S';  // Default: Stop

  if (yValue > 800)      command = 'F';  // Forward
  else if (yValue < 200) command = 'B';  // Backward
  else if (xValue < 200) command = 'L';  // Left
  else if (xValue > 800) command = 'R';  // Right
  else                   command = 'S';  // Stop

  driver.send((uint8_t *)&command, 1);
  driver.waitPacketSent();

  Serial.print("Sent: "); Serial.println(command);
  delay(100);
}
