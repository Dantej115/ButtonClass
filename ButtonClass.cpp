#include "ButtonClass.h"

TypeButton::~TypeButton(){}

void TypeButton::ButtonIdle()
{
    // Serial.println("Iddle"); // Uncomment for debbug
    if (digitalRead(this->ReadPin) == LOW)
    {
        this->State = DEBBOUNCE;
        this->LastTick = millis();
    }
}
void TypeButton::ButtonDebbounce()
{
    // Serial.println("debb"); //Uncomment for debbug
    if (millis() - this->LastTick > this->DebbounceTime)
    {
        if (digitalRead(this->ReadPin) == LOW)
        {
            this->State = PRESSED;
            this->ButtonPressed();
            // if (this->ButtonPressed == NULL) Serial.println("NULL!!"); //uncoment for debugg
        }
        else    this->State = IDLE;
    }
}
void TypeButton::ButtonIsPressed()
{
    // Serial.println("PRESS"); //Uncomment for debbug
    if (digitalRead(this->ReadPin) == HIGH)
    {
        this->ButtonNotPressed();
        this->State = IDLE;
    }
}

void TypeButton::ButtonTask()
{
    switch (this->State)
    {
    case IDLE:
        ButtonIdle();
        break;
    case DEBBOUNCE:
        ButtonDebbounce();
        break;
    case PRESSED:
        ButtonIsPressed();
        break;
    default:
        break;
    }
}
// ButtonSwitch methods
ButtonSwitch::ButtonSwitch(const uint8_t &ReadPin, const uint8_t &WritePin)
{
    this->State = IDLE;
    this->ReadPin = ReadPin;
    this->WritePin = WritePin;
    this->DebbounceTime = 50U;

    pinMode(this->ReadPin, INPUT_PULLUP);
    pinMode(this->WritePin, OUTPUT);
    digitalWrite(WritePin, LOW);
}
void ButtonSwitch::ButtonPressed()
{
    digitalWrite(WritePin, HIGH);
}
void ButtonSwitch::ButtonNotPressed()
{
    digitalWrite(WritePin, LOW);
}
void ButtonSwitch::SetButton(const uint8_t &ReadPin, const uint8_t &WritePin)
{
    this->State = IDLE;
    this->ReadPin = ReadPin;
    this->WritePin = WritePin;
    this->DebbounceTime = 50U;

    pinMode(this->ReadPin, INPUT_PULLUP);
    pinMode(this->WritePin, OUTPUT);
    digitalWrite(WritePin, LOW);
}
