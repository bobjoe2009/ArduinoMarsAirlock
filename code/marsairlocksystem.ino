#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo doorServo;

const int greenLED = 6;
const int yellowLED = 7;
const int redLED = 8;

int mode = 0;
unsigned long lastSwitch = 0;

int servoPos = 0;
int direction = 1;

void setup() {

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  doorServo.attach(9);
  doorServo.write(0);

  lcd.begin(16, 2);

  lcd.print("MARS BASE SYS");
  delay(2000);
  lcd.clear();
}

void loop() {

  switchMode();
  runSystem();
  display();
}

// ---------------- MODE SWITCH ----------------
void switchMode() {

  if (millis() - lastSwitch > 10000) {
    lastSwitch = millis();

    mode++;
    if (mode > 2) mode = 0;

    servoPos = 0;
    direction = 1;
  }
}

// ---------------- SYSTEM LOGIC ----------------
void runSystem() {

  // reset LEDs first
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  if (mode == 0) {
    // SAFE
    digitalWrite(greenLED, HIGH);
    doorServo.write(0);
  }

  else if (mode == 1) {
    // INVASION ALERT
    digitalWrite(yellowLED, HIGH);

    servoPos += direction;

    if (servoPos >= 45 || servoPos <= 0) {
      direction *= -1;
    }

    doorServo.write(servoPos);
    delay(15); // smooth movement
  }

  else if (mode == 2) {
    // LOCKDOWN
    digitalWrite(redLED, HIGH);
    doorServo.write(90);
  }
}

// ---------------- DISPLAY ----------------
void display() {

  lcd.setCursor(0, 0);

  if (mode == 0) lcd.print("STATUS: SAFE     ");
  if (mode == 1) lcd.print("INTRUDER ALERT   ");
  if (mode == 2) lcd.print("TOTAL LOCKDOWN   ");

  lcd.setCursor(0, 1);

  if (mode == 0) lcd.print("DOOR OPEN        ");
  if (mode == 1) lcd.print("SCANNING AREA    ");
  if (mode == 2) lcd.print("SYSTEM SEALED    ");
}
