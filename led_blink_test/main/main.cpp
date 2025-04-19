#include "Arduino.h"

extern "C" void app_main()
{
    const gpio_num_t BLINK_GPIO = GPIO_NUM_2;
    pinMode(BLINK_GPIO, OUTPUT);
    for (int j = 0; j < 10; j++)
    {
        switch (j)
        {
        case 0:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(50);
                digitalWrite(BLINK_GPIO, LOW);
                delay(10);
            }

            break;

        case 1:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(10);
                digitalWrite(BLINK_GPIO, LOW);
                delay(50);
            }

            break;

        case 2:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(50);
                digitalWrite(BLINK_GPIO, LOW);
                delay(50);
            }

            break;

        case 4:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(100);
                digitalWrite(BLINK_GPIO, LOW);
                delay(10);
            }

            break;

        case 5:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(10);
                digitalWrite(BLINK_GPIO, LOW);
                delay(100);
            }

            break;

        case 6:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(100);
                digitalWrite(BLINK_GPIO, LOW);
                delay(100);
            }

            break;

        case 7:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(200);
                digitalWrite(BLINK_GPIO, LOW);
                delay(10);
            }

            break;

        case 8:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(10);
                digitalWrite(BLINK_GPIO, LOW);
                delay(200);
            }

            break;

        case 9:

            /* code */
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(BLINK_GPIO, HIGH);
                delay(200);
                digitalWrite(BLINK_GPIO, LOW);
                delay(200);
            }

            break;
        }
    }
}
