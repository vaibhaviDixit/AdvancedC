/*
   Create a class 'Fraction' with attributes 'numerator' and 'denominator'.
   Implement functions to add two fractions and display the result in simplified form.
   Use objects to demonstrate fraction addition.
*/

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Function to add fractions
    void add(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
    }

    // Function to find greatest common divisor (GCD)
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    // Function to simplify the fraction
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    // Function to display the fraction
    void display() {
        std::cout << "Fraction: " << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Fraction frac1(3, 5);
    Fraction frac2(2, 7);

    frac1.add(frac2);
    frac1.display();

    return 0;
}

/*
This program defines a class Fraction with attributes numerator and denominator.
It has a method to add two fractions and display the result in simplified form.
The main function demonstrates the use of objects to add fractions.
*/
