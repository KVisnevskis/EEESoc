volatile int i;

void setup() {
  initTimerInterrupt();
  Serial.begin(9600);
}

void loop() {
  // do nothing
  Serial.println(i);
}

void initTimerInterrupt()
{
    // this code sets up the timer to cause an interrupt every 5ms
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
    // this is the function that will be called whenever
    i++; 
    if (i > 1000)
      i = 0;
}


