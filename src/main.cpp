// #include <Arduino.h>
#include <Esp.h>

#define LED_PIN D1
#define BLINK_DELAY 1000

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  
  Serial.println("Hello World!");
  // delay(1000);
  // // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);

  delay(BLINK_DELAY);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(BLINK_DELAY);
}