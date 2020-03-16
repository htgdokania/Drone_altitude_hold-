void setup() {
  //for SOftware interrupts
  PCICR |= (1 << PCIE0);    //enable PCMSK0 scan                                                 
  PCMSK0 |= (1 << PCINT2);  //Set pin D10 trigger an interrupt on state change.                                               
  PCMSK0 |= (1 << PCINT1);  //Set pin D9 trigger an interrupt on state change.                                               
  
  Serial.begin(250000);
  //for UltraSonic Sensor
  pinMode(echoPin1,INPUT);
  pinMode(trigPin1,OUTPUT);
  
  //throttle output pin
  channel3.attach(6);
  channel3.writeMicroseconds(1000);
}
