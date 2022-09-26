#ifndef BUTTONCLASS_H_
#define BUTTONCLASS_H_

#include <Arduino.h>

// states for machine
enum BUTTON_STATE
{
    IDLE = 0, DEBBOUNCE, PRESSED
};

//struct button
class TypeButton
{
protected:
    void ButtonIdle();
    void ButtonDebbounce();
    void ButtonIsPressed();
    virtual void ButtonPressed() = 0;
    virtual void ButtonNotPressed() = 0;

    BUTTON_STATE    State;
    uint8_t         ReadPin;
    uint16_t        DebbounceTime;
    unsigned long   LastTick;
public:
    virtual ~TypeButton() = 0;
    void ButtonTask();
};

class ButtonSwitch : public TypeButton
{
    void ButtonPressed();
    void ButtonNotPressed(); 
    uint8_t WritePin;

 public:

    ButtonSwitch() {};
    ~ButtonSwitch() {};
    ButtonSwitch(const uint8_t &ReadPin, const uint8_t &WritePin);
    void SetButton(const uint8_t &ReadPin, const uint8_t &WritePin);
};
#endif

