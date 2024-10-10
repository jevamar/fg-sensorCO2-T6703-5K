// #include <Arduino.h>
#include <Esp.h>

#define PIN_TRIG D2
#define PIN_ECHO D3
#define LED_PIN D1
#define BLINK_DELAY 1000

unsigned long timerLed = 0;
unsigned long duration, cm;

// put function declarations here:
void handleSonar();

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  delay(300);
}

void loop() {
  handleSonar();

  if(millis() - timerLed >= 2000) {
    timerLed = millis();
    
    // Serial.print("LED: turn on. ");
    // Serial.println(timerLed);
    
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);

    delay(BLINK_DELAY);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    // delay(BLINK_DELAY);
  }
}

void handleSonar() 
{
  // Создаем короткий импульс длительностью 5 микросекунд.
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  // Установим высокий уровень сигнала
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  //  Определяем задержку сигнала
  duration = pulseIn(PIN_ECHO, HIGH);
  // Преобразуем время задержки в расстояние
  cm = (duration / 2) / 29.1;
  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");
  // Задержка между измерениями
  delay(250);
}