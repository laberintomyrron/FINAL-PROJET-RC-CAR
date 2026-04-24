#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

int enableRightMotor = 14;
int rightMotorPin1 = 4;
int rightMotorPin2 = 2;

int enableLeftMotor = 27;
int leftMotorPin1 = 15;
int leftMotorPin2 = 13;

#define MAX_MOTOR_SPEED 255

const int PWMFreq = 1000;
const int PWMResolution = 8;
const int rightMotorPWMSpeedChannel = 0;
const int leftMotorPWMSpeedChannel  = 1;

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  if (rightMotorSpeed < 0) {                                                                                                              
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
  ledcWrite(leftMotorPWMSpeedChannel,  abs(leftMotorSpeed));
}

void setUpPinModes() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1,   OUTPUT);
  pinMode(rightMotorPin2,   OUTPUT);
  pinMode(enableLeftMotor,  OUTPUT);
  pinMode(leftMotorPin1,    OUTPUT);
  pinMode(leftMotorPin2,    OUTPUT);

  ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);
  ledcSetup(leftMotorPWMSpeedChannel,  PWMFreq, PWMResolution);
  ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
  ledcAttachPin(enableLeftMotor,  leftMotorPWMSpeedChannel);

  rotateMotor(0, 0);
}

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 Starting...");
  setUpPinModes();
  Serial.println("Pins set up done.");
  Dabble.begin("RCKOYAN");
  Serial.println("Bluetooth started! Name: RCKOYAN");
}

void loop() {
  int rightMotorSpeed = 0;
  int leftMotorSpeed  = 0;

  Dabble.processInput();

  // RIGHT button → Forward
  if (GamePad.isRightPressed()) {
    rightMotorSpeed =  MAX_MOTOR_SPEED;
    leftMotorSpeed  =  MAX_MOTOR_SPEED;
  }

  // LEFT button → Backward
  if (GamePad.isLeftPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed  = -MAX_MOTOR_SPEED;
  }

  // DOWN button → Turn Right
  if (GamePad.isDownPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed  =  MAX_MOTOR_SPEED;
  }

  // UP button → Turn Left
  if (GamePad.isUpPressed()) {
    rightMotorSpeed =  MAX_MOTOR_SPEED;
    leftMotorSpeed  = -MAX_MOTOR_SPEED;
  }

  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}