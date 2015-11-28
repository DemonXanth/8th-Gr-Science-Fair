#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  160 
#define SERVOMAX  750 

uint8_t s1 = 0;
uint8_t s2 = 3;
uint8_t s3 = 4;
uint8_t s4 = 7;

int f1 = A0;
int f2 = A1;
int f3 = A2;
int f4 = A3;

int p1 = A4;
int p2 = A5;

int lf1 = 1;
int lf2 = 1;

void setup(){
  Serial.begin(9600);
  
  pwm.begin();
  
  pwm.setPWMFreq(100);
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop(){
  int fr1 = analogRead(f1);
  int fr2 = analogRead(f2);
  
  Serial.print("flex1SensorReading:");
  Serial.println(fr1);
  Serial.print("flex2SensorReading:");
  Serial.println(fr2);
  
  int flex1 = map(fr1, 100, 300, 0, 180);
  int flex2 = map(fr2, 100, 300, 0, 180);
  flex1 = constrain(flex1, 0, 180);
  flex2 = constrain(flex2, 0, 180);
  Serial.print("flex1:");
  Serial.println(flex1);
  Serial.print("flex2:");
  Serial.println(flex2);
  
  for (uint16_t pulselen = flex1; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(s1, 0, pulselen);
  }
  if(flex1 != lf1){
    delay(1000);
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
      pwm.setPWM(s1, 0, pulselen);
    }
  }
  delay(100);
  
  int lf1 = flex1;
  int lf2 = flex2;
}
