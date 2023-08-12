/*
Implement a class to manage a bank account, with options for deposit, withdrawal, and checking the account balance.

Input:
BankAccount account("John Doe", 5000)
account.checkBalance()
account.deposit(2000)
account.checkBalance()
account.withdraw(3000)
account.checkBalance()

Output:

Account Holder: John Doe, Balance: 5000
Account Holder: John Doe, Balance: 7000
Account Holder: John Doe, Balance: 4000


*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class BankAccount {
private:
    string accountHolder; // Private member variable to store the name of the account holder.
    double balance; // Private member variable to store the balance of the bank account.

public:
    BankAccount(string holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {
        // Constructor to initialize the BankAccount object with the provided account holder name and initial balance.
    }

    void deposit(double amount) {
        balance += amount; // Member function to deposit money into the bank account by adding the amount to the balance.
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount; // Member function to withdraw money from the bank account if the balance is sufficient.
        } else {
            cout << "Insufficient balance." << endl; // Display a message if the withdrawal amount exceeds the balance.
        }
    }

    void checkBalance() {
        cout << "Account Holder: " << accountHolder << ", Balance: " << balance << endl;
        // Member function to display the account holder name and the current balance of the bank account.
    }
};

int main() {
    BankAccount account("John Doe", 5000); // Create a BankAccount object named 'account' with an initial balance of 5000.
    account.checkBalance(); // Display the account holder name and balance.

    account.deposit(2000); // Deposit 2000 into the bank account.
    account.checkBalance(); // Display the updated balance after the deposit.

    account.withdraw(3000); // Withdraw 3000 from the bank account.
    account.checkBalance(); // Display the updated balance after the withdrawal.

    return 0; // Exit the program with a success status.
}

/*
This C++ program defines a BankAccount class to represent a simple bank account. The class has private member variables accountHolder to store the name of the account holder and balance to store the current balance.

The class provides three member functions:

The constructor BankAccount is used to initialize a BankAccount object with the provided account holder name and initial balance.
The deposit member function is used to add money to the bank account by increasing the balance.
The withdraw member function is used to withdraw money from the bank account, but it checks if the account has sufficient balance before making the withdrawal. If the balance is insufficient, it displays a message to inform the user.
The checkBalance member function is used to display the account holder name and the current balance of the bank account.
In the main function, it creates a BankAccount object named account with an initial balance of 5000. It then performs a series of operations on the account, such as checking the initial balance, depositing 2000, withdrawing 3000, and checking the updated balance after each operation. The results of these operations are displayed on the console.

*/

