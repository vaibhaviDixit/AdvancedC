/*
Create an abstract base class Payment with a pure virtual function makePayment(). Implement derived classes CreditCardPayment and
CashPayment that override the makePayment() function to perform payment operations.

Input:
    Payment* payment1 = new CreditCardPayment();
    Payment* payment2 = new CashPayment();

    payment1->makePayment();
    payment2->makePayment();

Output:

Credit card payment made.
Cash payment made.



*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
#include <string> // Include the string library to work with strings.
using namespace std; // Use the standard namespace to access standard library elements directly.


class Payment {
public:
    virtual void makePayment() = 0; // Pure virtual function to perform a payment (no implementation).
};

// Derive a class 'CreditCardPayment' from the base class 'Payment' to represent credit card payments.
class CreditCardPayment : public Payment {
public:
    void makePayment() override {
        cout << "Credit card payment made." << endl;
        // Implementation of the 'makePayment()' method to perform a credit card payment.
    }
};

// Derive a class 'CashPayment' from the base class 'Payment' to represent cash payments.
class CashPayment : public Payment {
public:
    void makePayment() override {
        cout << "Cash payment made." << endl;
        // Implementation of the 'makePayment()' method to perform a cash payment.
    }
};

int main() {
    Payment* payment1 = new CreditCardPayment(); // Create a Payment pointer pointing to a dynamically allocated CreditCardPayment object.
    Payment* payment2 = new CashPayment(); // Create a Payment pointer pointing to a dynamically allocated CashPayment object.

    payment1->makePayment(); // Dynamic binding to CreditCardPayment's makePayment() - Polymorphism.
    payment2->makePayment(); // Dynamic binding to CashPayment's makePayment() - Polymorphism.

    delete payment1; // Deallocate the memory for the CreditCardPayment object.
    delete payment2; // Deallocate the memory for the CashPayment object.

    return 0; // Exit the program with a success status.
}


/*
This C++ program demonstrates the concept of abstract classes and dynamic binding using a common base class Payment. The Payment class is an abstract class because it defines a pure virtual function makePayment(), which has no implementation in the base class and is intended to be overridden in derived classes.

Two derived classes, CreditCardPayment and CashPayment, inherit from the Payment base class. The CreditCardPayment class represents credit card payments and provides an implementation for the makePayment() method to perform a credit card payment. The CashPayment class represents cash payments and provides an implementation for the makePayment() method to perform a cash payment.

In the main() function, two pointers payment1 and payment2 of type Payment are created and initialized with the addresses of dynamically allocated objects of the CreditCardPayment and CashPayment classes, respectively. This demonstrates polymorphism through dynamic binding, where the correct makePayment() method from the respective derived class is invoked based on the object type.

When payment1->makePayment() is called, the makePayment() method of the CreditCardPayment class is executed, indicating that a credit card payment is made. Similarly, when payment2->makePayment() is called, the makePayment() method of the CashPayment class is executed, indicating that a cash payment is made.

After performing the payments, the dynamically allocated memory for the CreditCardPayment and CashPayment objects is deallocated using the delete keyword to avoid memory leaks. Finally, the program exits with a success status.

*/

