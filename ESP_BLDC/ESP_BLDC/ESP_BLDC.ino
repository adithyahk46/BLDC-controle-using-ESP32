#include <ESP32Servo.h>

Servo ESC; 

const int potPin = 34;
int V_res = 0;
int Speed;

void setup(){
  Serial.begin(115200);
 delay(1000);
ESC.attach(14,1000,2000);
}

void loop(){
  
  V_res = analogRead(potPin)/4.01;
  Speed = map(V_res, 0, 1023, 0, 180);
  ESC.write(Speed);
  Serial.print(V_res);Serial.print("\t");
  Serial.println(Speed);

}

// // Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
// const int potPin = 34;

// // variable for storing the potentiometer value
// int potValue = 0;

// void setup() {
//   Serial.begin(115200);
//   delay(1000);
// }

// void loop() {
//   // Reading potentiometer value
//   potValue = analogRead(potPin);
//   Serial.println(potValue);
//   delay(500);
// }