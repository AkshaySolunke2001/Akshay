#include <iostream>
#include "add.h"
#include "sub.h"
#include "multi.h"
#include "div.h"

int main() {
    int cal, c, d;

    std::cout << "Enter number A: ";
    std::cin >> c;
    std::cout << "Enter number B: ";
    std::cin >> d;

    std::cout << "Choose operation:\n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    std::cin >> cal;

    switch (cal) {
        case 1: {
            sum sm;
            std::cout << "Sum = " << sm.Add(c, d) << std::endl;
            break;
        }
        case 2: {
            sub sb;
            std::cout << "Sub = " << sb.Sub(c, d) << std::endl;
            break;
        }
        case 3: {
            multi mt;
            std::cout << "Mul = " << mt.Multi(c, d) << std::endl;
            break;
        }
        case 4: {
            divi dv;
            std::cout << "Div = " << dv.Div(c, d) << std::endl;
            break;
        }
        default:
            std::cout << "Invalid operation selected!" << std::endl;
    }

    return 0;
}
