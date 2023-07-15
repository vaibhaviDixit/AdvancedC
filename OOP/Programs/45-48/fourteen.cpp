/*
Create a class "Temperature" to represent temperature in Celsius.
Implement an explicit constructor to convert Celsius to Fahrenheit.
*/

#include <iostream>

class Temperature {
private:
    double celsius;

public:
    // Explicit Constructor to convert Celsius to Fahrenheit
    explicit Temperature(double tempCelsius) {
        celsius = tempCelsius;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }
};

int main() {
    Temperature tempCelsius(25.5);
    std::cout << "Temperature in Celsius: " << tempCelsius.getCelsius() << std::endl;
    std::cout << "Temperature in Fahrenheit: " << tempCelsius.getFahrenheit() << std::endl;
    return 0;
}

/*
This program defines a class Temperature to represent temperature in Celsius.
The constructor takes tempCelsius as an argument and sets the celsius member variable.
The getFahrenheit() method converts Celsius to Fahrenheit and returns the result.
The constructor is marked as explicit to prevent implicit conversions from Celsius to Fahrenheit.
*/


