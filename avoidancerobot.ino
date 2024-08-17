
#include <Arduino.h>
#include "mecanum_w.h"
#include <algorithm>

bool isUltrasonicSensorWorking() {
    int distance = Get_Sonar();

    // Check if the distance reading is within a reasonable range
    if (distance > 0 && distance < 400) { // Assuming the sensor can detect up to 400 cm
        Serial.print("Ultrasonic Sensor Working: Distance = ");
        Serial.println(distance);
        return true;
    } else {
        Serial.println("Ultrasonic Sensor Error: No valid reading.");
        return false;
    }
}

void setup() {
    Serial.begin(9600);

    // Check if the ultrasonic sensor is working
    if (!isUltrasonicSensorWorking()) {
        Serial.println("Error: Ultrasonic sensor is not working.");
        while (true) {
            // Stay in an infinite loop if the sensor is not working
            delay(1000);
        }
    }

    // Initialize other components
    Ultrasonic_Setup();
    Motor_Setup();
    Servo_Setup();
}

void loop() {
    // Main code for obstacle avoidance
    Ultrasonic_Car();
}
