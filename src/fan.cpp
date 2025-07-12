#include "fan.h"
#include <Arduino.h>

Fan::Fan(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void Fan::SetSpeed(Speed speed) {
    switch (speed) {
    case Speed::OFF:
        digitalWrite(pin, LOW);
        break;
    case Speed::SLOW:
        analogWrite(pin, 75);
        break;
    case Speed::MODERATE:
        analogWrite(pin, 125);
        break;
    case Speed::FAST:
        analogWrite(pin, 255);
        break;
    }
}