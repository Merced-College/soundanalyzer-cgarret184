#include "SoundSensor.h"
#include "SoundAnalyzer.h"

// Initialize objects
SoundSensor sensor(A0);           
SoundAnalyzer analyzer(150, 400); // Quiet < 150, Medium < 500, else Loud

void setup() {
    Serial.begin(9600);
    while (!Serial); // Wait for Serial Monitor to open
    sensor.begin();
    Serial.println("Sound Classification System Initialized...");
}

void loop() {
    // 1. Get raw data from hardware class
    int soundLevel = sensor.getSoundLevel();

    // 2. Process data using logic class
    std::string result = analyzer.classifySound(soundLevel);

    // 3. Output results
    Serial.print("Raw Level: ");
    Serial.print(soundLevel);
    Serial.print(" | Category: ");
    Serial.println(result.c_str());

    delay(200); // Faster polling for better responsiveness
}