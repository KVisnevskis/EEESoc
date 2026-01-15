// definitions of the PIC constants
#define Kp  100
#define Kd  0.01
#define Ki  0.15

#define sampleTime  0.005
#define targetAngle 0

#define RAD_TO_DEG 57.2958

// volatile global variables that will be used in ISR
volatile int motorPower;
volatile float accAngle; 
volatile float currentAngle, prevAngle=0;
volatile float error, prevError=0, errorSum=0;

int16_t accY, accZ; // accel reading variables

void setup() {
  // TODO: initialize all input/output pins required
  // TODO: initialize sensor
  init_interrupt();
}

void loop() {
  // TODO: measure the acc outputs
  // TODO: set motor speeds/direction
}

void init_interrupt()
{
    cli();                      // disable global interrupts
    TCCR1A = 0;                 // set entire TCCR1A register to 0
    TCCR1B = 0;                 // same for TCCR1B    
    OCR1A = 9999;               // set timer for 5s
    TCCR1B |= (1 << WGM12);     // turn on CTC mode
    TCCR1B |= (1 << CS11);      // Set CS11 bit for prescaling by 8
    TIMSK1 |= (1 << OCIE1A);    // enable timer compare interrupt
    sei();                      // enable global interrupts
}

ISR(TIMER1_COMPA_vect)
{
    // calculate the angle of inclination
    accAngle = atan2(accY, accZ)*RAD_TO_DEG;
    currentAngle = accAngle;
    // calculate error
    error = currentAngle - targetAngle;
    errorSum = errorSum + error;  
    errorSum = constrain(errorSum, -300, 300);

    //calculate output from Kp, Ki and Kd values
    motorPower = Kp*(error) + Ki*(errorSum)*sampleTime - Kd*(currentAngle-prevAngle)/sampleTime;
    prevAngle = currentAngle;
}

// TODO: add motor speed setting functions
