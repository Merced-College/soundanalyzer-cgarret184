#include "SoundSensor.h"
#include <Arduino.h>

// Constructor: Store the pin
SoundSensor::SoundSensor(int sensorPin) {
    pin = sensorPin;
}

// Initialize sensor: Set the pin mode
void SoundSensor::begin() {
    pinMode(pin, INPUT);
}

// Read sound level: Return 0-1023 value
int SoundSensor::getSoundLevel() {
    int value = analogRead(pin);
    return value; 
}