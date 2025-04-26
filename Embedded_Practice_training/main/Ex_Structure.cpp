#include <stdio.h>
#include <Arduino.h>
#include "Ex_Structure.h"

extern "C";
void get_student_data(){

    int n;


    Serial.println("Enter value of n");
    while (Serial.available() == 0);
    n = Serial.parseInt();
    sys_delay_ms(1000);

    struct sudent_list MSc_First[n];

    for(int i = 0; i < n; i++)
    {

    


        Serial.println("Enter Student name");
        while (Serial.available() == 0);
        String tempName = Serial.readStringUntil('\n');
        sys_delay_ms(1000);
        tempName.trim();
        strncpy(MSc_First[i].S_name, tempName.c_str(), sizeof(MSc_First[i].S_name) - 1);
        MSc_First[i].S_name[sizeof(MSc_First[i].S_name) - 1] = '\0';


        Serial.println("Student_Age");
        while (Serial.available() == 0);
        MSc_First[i].S_age = Serial.parseInt();
        sys_delay_ms(1000);


        Serial.println("Student_weight");
        while (Serial.available() == 0);
        MSc_First[i].S_weight = Serial.parseInt();
        sys_delay_ms(1000);


        Serial.println("Student_hight in cm");
        while (Serial.available() == 0);
        MSc_First[i].S_hight_cm = Serial.parseInt();
        sys_delay_ms(1000);


        Serial.println("MSc_Subject_group");
        while (Serial.available() == 0);
        String temp1Name = Serial.readStringUntil('\n');
        sys_delay_ms(1000);
        temp1Name.trim();
        strncpy(MSc_First[i].subject_group, temp1Name.c_str(), sizeof(MSc_First[i].subject_group) - 1);
        MSc_First[i].subject_group[sizeof(MSc_First[i].subject_group) - 1] = '\0';
        
    }


       // Print student data
       for (int i = 0; i < n; i++) {
        Serial.print("Name: "); Serial.print(MSc_First[i].S_name);
        Serial.print(" | Age: "); Serial.print(MSc_First[i].S_age);
        Serial.print(" | Weight: "); Serial.print(MSc_First[i].S_weight);
        Serial.print(" | Height: "); Serial.print(MSc_First[i].S_hight_cm);
        Serial.print(" | Group: "); Serial.println(MSc_First[i].subject_group);

    }

}