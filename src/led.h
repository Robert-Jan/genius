#ifndef LED_H
#define LED_H
#include <NeoPixelBus.h>

class Led {
public:
    enum Color {
        RED,
        GREEN,
        BLUE,
        WHITE,
    };
private:
    int pin;
    NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod>* strip;
public:
    Led(int pin);
    void SetColor(Color color);
};

#endif