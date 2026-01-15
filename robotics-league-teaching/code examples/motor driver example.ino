#define MOTOR_DIR_PIN_1 3 // direction pins
#define MOTOR_DIR_PIN_2 4
#define MOTOR_PWM_PIN   5 // motor power pin

void setup() {
  // set pins as output
  pinMode(MOTOR_DIR_PIN_1, OUTPUT);
  pinMode(MOTOR_DIR_PIN_2, OUTPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);
}

void loop() {
  // set motors in forward direction
  digitalWrite(MOTOR_DIR_PIN_1, HIGH);
  digitalWrite(MOTOR_DIR_PIN_2, LOW);
  // set motor speed to half speed
  analogWrite(MOTOR_PWM_PIN, 128);
  delay(1000);
  // reduce motor speed
  analogWrite(MOTOR_PWM_PIN, 64);
  delay(1000);

  // set motors in the reverse direction
  digitalWrite(MOTOR_DIR_PIN_1, HIGH);
  digitalWrite(MOTOR_DIR_PIN_2, LOW);
  // set motor speed to half speed
  analogWrite(MOTOR_PWM_PIN, 128);
  delay(1000);
  // reduce motor speed
  analogWrite(MOTOR_PWM_PIN, 64);
  delay(1000);
}
