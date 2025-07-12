#ifndef FAN_H
#define FAN_H

class Fan {
public:
    enum Speed {
        OFF,
        SLOW,
        MODERATE,
        FAST,
    };
private:
    int pin;
public:
    Fan(int pin);
    void SetSpeed(Speed speed);
};

#endif