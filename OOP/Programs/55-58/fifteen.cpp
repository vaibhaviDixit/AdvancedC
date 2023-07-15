/*
Create a base class Calculator with methods for addition and subtraction.
Derive a class ScientificCalculator from Calculator and add methods for multiplication and division.
*/

#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
};

class ScientificCalculator : public Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }

    int divide(int a, int b) {
        if (b == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return 0;
        }
        return a / b;
    }
};

int main() {
    ScientificCalculator sc;
    int a = 10, b = 3;

    std::cout << "Addition: " << sc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << sc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << sc.multiply(a, b) << std::endl;
    std::cout << "Division: " << sc.divide(a, b) << std::endl;

    return 0;
}
