#define encoderPinA 2
#define encoderPinB 3
long encoderPos = 0;
void doEncoderA(){
  encoderPos+= digitalRead(encoderPinA) == digitalRead(encoderPinB)?1:-1;
}
void doEncoderB(){
  encoderPos+= digitalRead(encoderPinA) == digitalRead(encoderPinB)?-1:1;
}

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  attachInterrupt(0,doEncoderA,CHANGE);
  attachInterrupt(1,doEncoderB,CHANGE);
  Serial.begin(9600);
}

void loop() {
  Serial.print("encoderPos :");
  Serial.println(encoderPos);
  // Serial.print("pinA :");
  // Serial.print(digitalRead(encoderPinA));
  // Serial.print(" pinB : ");
  // Serial.println(digitalRead(encoderPinB));
  delay(10);
}
