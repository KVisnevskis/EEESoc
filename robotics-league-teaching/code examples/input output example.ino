// assigning pin value to variables
#define DIGITAL_PIN_IN   5
#define DIGITAL_PIN_OUT  4  

// alternatively use variables
int analog_pin_in = 5;
int analog_pin_out = A0;

void setup() {
  pinMode(DIGITAL_PIN_IN, INPUT); // setup digital input pin
  pinMode(DIGITAL_PIN_OUT, OUTPUT);  // setup digital input pin
  pinMode(analog_pin_in, INPUT); // setup analog output pin
  pinMode(analog_pin_out, OUTPUT);  // setup analog input pin
}

void loop() {
  // reading digital input
  int digital_value = digitalRead(DIGITAL_PIN_IN);
  
  // reading analog value
  int analog_value = analogRead(analog_pin_in);

  // writing/setting digital pin output
  digitalWrite(DIGITAL_PIN_OUT, HIGH);
  digitalWrite(DIGITAL_PIN_OUT, LOW);

  // writing analog pin (PWM output)
  for (int i = 0; i < 255; i++)
    analogWrite(analog_pin_out, i);

}
