#include <Arduino.h>
#include "fan.h"
#include "led.h"

const int BAUT_RATE = 115200;

const int PIN_BUTTON_REAR = 3;
const int PIN_BUTTON_CONNECT = 16;
const int PIN_FAN = 4;
const int PIN_LED = 15;

Fan fan(PIN_FAN);
Led led(PIN_LED);

void setup() {
  Serial.begin(BAUT_RATE);

  Serial.println("-------------------------");
  Serial.println("Starting Genius Device...");
  Serial.println("-------------------------");

  pinMode(PIN_BUTTON_REAR, INPUT);
  pinMode(PIN_BUTTON_CONNECT, INPUT);
}

void loop() {
  if (digitalRead(PIN_BUTTON_REAR) == LOW) {
    led.SetColor(Led::Color::RED);
    fan.SetSpeed(Fan::Speed::MODERATE);
    Serial.println("Rear button pressed");
  }
  else if (digitalRead(PIN_BUTTON_CONNECT) == LOW) {
    led.SetColor(Led::Color::GREEN);
    fan.SetSpeed(Fan::Speed::FAST);
    Serial.println("Connect button pressed");
  }
  else {
    led.SetColor(Led::Color::BLUE);
    fan.SetSpeed(Fan::Speed::OFF);
  }

  delay(1);
}