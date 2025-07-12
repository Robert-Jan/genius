#include "led.h"
#include <Arduino.h>
#include <NeoPixelBus.h>

Led::Led(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);

    strip = new NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod>(1, pin);
    strip->Begin();
}

void Led::SetColor(Color color) {
    switch (color)
    {
    case Color::RED:
        strip->SetPixelColor(0, RgbColor(255, 0, 0));
        break;
    case Color::GREEN:
        strip->SetPixelColor(0, RgbColor(0, 255, 0));
        break;
    case Color::BLUE:
        strip->SetPixelColor(0, RgbColor(0, 0, 255));
        break;
    case Color::WHITE:
        strip->SetPixelColor(0, RgbColor(255, 255, 255));
        break;
    default:
        strip->SetPixelColor(0, RgbColor(0, 0, 0));
        break;
    }

    strip->Show();
}