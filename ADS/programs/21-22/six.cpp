/*
Create a class to represent complex numbers and implement functions to add and multiply two complex numbers.

Input:
Complex c1(2, 3)
Complex c2(1, -1)

Output:
Sum: 3 + 2i
Product: 5 + 1i

*/

#include <iostream> // Include the iostream library to enable input and output stream operations.

using namespace std; // Use the standard namespace to access standard library elements directly.

class Complex {
private:
    double real; // Private member variable to store the real part of the complex number.
    double imag; // Private member variable to store the imaginary part of the complex number.

public:
    Complex(double r, double i) : real(r), imag(i) {} // Constructor to initialize the Complex object with provided real and imaginary values.

    Complex add(Complex c) { // Member function to add two complex numbers.
        return Complex(real + c.real, imag + c.imag);
    }

    Complex multiply(Complex c) { // Member function to multiply two complex numbers.
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    void display() { // Member function to display the complex number in the format "real + imagi".
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3); // Create a Complex object c1 with real part 2 and imaginary part 3.
    Complex c2(1, -1); // Create a Complex object c2 with real part 1 and imaginary part -1.

    Complex sum = c1.add(c2); // Add c1 and c2, store the result in the 'sum' variable.
    Complex product = c1.multiply(c2); // Multiply c1 and c2, store the result in the 'product' variable.

    cout << "Sum: ";
    sum.display(); // Display the sum of the two complex numbers.

    cout << "Product: ";
    product.display(); // Display the product of the two complex numbers.

    return 0; // Exit the program with a success status.
}

/*
This C++ program defines a Complex class to represent complex numbers. It has two private member variables, real and imag, to store the real and imaginary parts of a complex number, respectively. The class provides two member functions, add and multiply, to perform addition and multiplication operations on complex numbers.

In the main function, it creates two Complex objects c1 and c2 with specified real and imaginary parts. It then performs addition and multiplication of these two complex numbers using the add and multiply member functions of the Complex class and stores the results in sum and product variables, respectively.

Finally, it displays the sum and product of the complex numbers on the console using the display member function.

*/


