// Megatron - Bluetooth Controlled Robot Car with Kicking Mechanism

// 🔌 Motor Driver Pins (L298N)
const int ENA = 5;     // Left motor enable (PWM)
const int IN1 = 2;
const int IN2 = 3;

const int ENB = 6;     // Right motor enable (PWM)
const int IN3 = 4;
const int IN4 = 7;

// ⚙️ Servo Pin
#include <Servo.h>
Servo kicker;
const int servoPin = 9;

// 📲 Bluetooth Receiver
char receivedChar;

void setup() {
  // Initialize motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize Servo
  kicker.attach(servoPin);
  kicker.write(0);  // Start position

  // Start serial communication with HC-05
  Serial.begin(9600);
}

void loop() {
  // Read incoming Bluetooth command
  if (Serial.available() > 0) {
    receivedChar = Serial.read();

    switch (receivedChar) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotors(); break;
      case 'K': kick(); break;
    }
  }
}

// 🚗 Movement Functions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// ⚽ Kick Function
void kick() {
  kicker.write(90);       // Push forward
  delay(300);             // Wait for kick
  kicker.write(0);        // Return
  delay(300);
}
