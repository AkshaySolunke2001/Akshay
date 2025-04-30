#include "Arduino.h"

extern "C" void app_main()
{
    const gpio_num_t BLINK_GPIO = GPIO_NUM_2;
    pinMode(BLINK_GPIO, OUTPUT);

while(1){


    for (int j = 0; j < 10; j++)
    {
        switch (j)
        {
        case 0:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(5);
                digitalWrite(BLINK_GPIO, LOW);
                delay(5);
            }

            break;

        case 1:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(7);
                digitalWrite(BLINK_GPIO, LOW);
                delay(7);
            }

            break;

        case 2:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(10);
                digitalWrite(BLINK_GPIO, LOW);
                delay(10);
            }

            break;

        case 4:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(15);
                digitalWrite(BLINK_GPIO, LOW);
                delay(15);
            }

            break;

        case 5:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(20);
                digitalWrite(BLINK_GPIO, LOW);
                delay(20);
            }

            break;

        case 6:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(25);
                digitalWrite(BLINK_GPIO, LOW);
                delay(25);
            }

            break;

        case 7:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(30);
                digitalWrite(BLINK_GPIO, LOW);
                delay(30);
            }

            break;

        case 8:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(35);
                digitalWrite(BLINK_GPIO, LOW);
                delay(35);
            }

            break;

        case 9:

            /* code */
            for (int i = 0; i < 100; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(40);
                digitalWrite(BLINK_GPIO, LOW);
                delay(40);
            }

            break;
        }
    }
}
}
