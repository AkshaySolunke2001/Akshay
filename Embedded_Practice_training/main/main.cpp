#include <Arduino.h>
#include "add.h"
#include "div.h"
#include "multi.h"
#include "sub.h"
#include "Ex_Structure.h"
#include "Ex_Union.h"

extern "C" void app_main() {
    // Start serial communication at 115200 baud rate
    Serial.begin(115200);
    
    // Wait until the serial monitor is ready
    while (!Serial) {
        // Wait for the serial port to connect (needed for native USB)
    }
    
    // Declare variables for input and calculation choice
    int cal;
    int c, d;
    
    // Ask the user to input two numbers for the operation
    Serial.println("Enter the value of number A and number B:");
    
    // Wait for user input and read the first number
    while (Serial.available() == 0) {
        // Wait for user input
    }
    c = Serial.parseInt();  // Read the first number
    sys_delay_ms(1000);

    
    // Wait for user input and read the second number
    while (Serial.available() == 0) {
        // Wait for user input
    }
    d = Serial.parseInt();  // Read the second number
    sys_delay_ms(1000);
    
    // Ask the user to choose the operation
    Serial.println("Enter the value between 1 and 4 for calculation:");
    Serial.println("1. Addition");
    Serial.println("2. Subtraction");
    Serial.println("3. Multiplication");
    Serial.println("4. Division");
    
    // Wait for the operation choice from the user
    while (Serial.available() == 0) {
        // Wait for user input
    }
    cal = Serial.parseInt();  // Read the operation choice
    sys_delay_ms(1000);
    
    // Perform the chosen operation
    switch (cal) {
        case 1: {  // For addition
            sum sm;
            int result = sm.Add(c, d);
            Serial.print("Sum = ");
            Serial.println(result);
            break;
        }

        case 2: {  // For subtraction
            sub sb;
            int result = sb.Sub(c, d);
            Serial.print("Difference = ");
            Serial.println(result);
            break;
        }

        case 3: {  // For multiplication
            multi mt;
            int result = mt.Multi(c, d);
            Serial.print("Product = ");
            Serial.println(result);
            break;
        }

        case 4: {  // For division
            divi dv;
            if (d != 0) {
                double result = dv.Div(c, d);
                Serial.print("Quotient = ");
                Serial.println(result);
            } else {
                Serial.println("Error: Division by zero is not allowed.");
            }
            break;
        }

        default:
            Serial.println("Invalid input. Please enter a number between 1 and 4.");
    }


    // this function is getting student data from user using structure data type and and print it 
    get_student_data();




    // getting  planet name from user and print distance from sun to planet in million km
    // practice for union
    get_planet_distance_from_sun();



    

}

