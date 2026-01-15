void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // enable serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!"); // print text to the serial monitor
  delay(1000);                    // delay to avoid printing too often
}
