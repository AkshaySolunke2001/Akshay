#include "Ex_Union.h"
#include <Arduino.h>


String planeta_names[PLANET_COUNT] = {
    "Mercury", "Venus", "Earth", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptune"
};

float planet_distances[PLANET_COUNT] = {
    57.9, 108.2, 149.6, 227.9,
    778.5, 1433.5, 2872.5, 4495.1
};

void get_planet_distance_from_sun() {
    union Distance_from_Sun_to_planet planet_data;

    Serial.println("Enter the planet name:");
    while (Serial.available() == 0);
    String input = Serial.readStringUntil('\n');
    sys_delay_ms(1000);
    input.trim();
    input.toLowerCase();

    bool found = false;

    for (int i = 0; i < PLANET_COUNT; i++) {
        String nameLower = planeta_names[i];
        nameLower.toLowerCase();

        if (input == nameLower) {
            // First, store the enum in the union
            planet_data.planet_enum = static_cast<Planet>(i);

            // Now overwrite the union with distance value
            planet_data.distance_from_Sun = planet_distances[planet_data.planet_enum];

            Serial.print(planeta_names[planet_data.planet_enum]);
            Serial.print(": ");
            Serial.print(planet_data.distance_from_Sun);
            Serial.println(" million km from the Sun");

            found = true;
            break;
        }
    }

    if (!found) {
        Serial.println("Invalid planet name.");
    }
}

