/*
Write a C++ program for getting factorial of large number.

Input: 18
Output:  6402373705728000

Input: 29
Output:  8841761993739701954543616000000


*/

#include <bits/stdc++.h>
using namespace std;

class BigInt {
    string num; // Stores a large integer as a string of digits
public:
    BigInt(unsigned long long n = 0); // Constructor to initialize with an unsigned long long
    friend void divideByTwo(BigInt &a); // Friend function to divide the BigInt by 2
    friend bool Null(const BigInt &); // Friend function to check if BigInt is zero
    BigInt &operator=(const BigInt &); // Assignment operator overload
    friend BigInt &operator*=(BigInt &, const BigInt &); // Friend function to multiply BigInts in-place
    friend ostream &operator<<(ostream &, const BigInt &); // Friend function to output BigInt to stream
    friend BigInt getFactorial(int n); // Friend function to calculate the factorial of an integer
};

// Constructor to initialize a BigInt with an unsigned long long
BigInt::BigInt(unsigned long long nr) {
    do {
        num.push_back(nr % 10); // Extract the last digit and add it to the string
        nr /= 10; // Remove the last digit from the number
    } while (nr);
}

// Friend function to check if a BigInt is zero
bool Null(const BigInt &a) {
    if (a.num.size() == 1 && a.num[0] == 0)
        return true;
    return false;
}

// Assignment operator overload
BigInt &BigInt::operator=(const BigInt &a) {
    num = a.num;
    return *this;
}

// Friend function to multiply BigInts in-place
BigInt &operator*=(BigInt &a, const BigInt &b) {
    if (Null(a) || Null(b)) {
        a = BigInt(); // Set a to zero if either operand is zero
        return a;
    }
    int n = a.num.size(), m = b.num.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.num[i]) * (b.num[j]);
        }
    n += m;
    a.num.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++) {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.num[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        a.num.pop_back();
    return a;
}

// Friend function to divide a BigInt by 2
void divideByTwo(BigInt &a) {
    int add = 0;
    for (int i = a.num.size() - 1; i >= 0; i--) {
        int digit = (a.num[i] >> 1) + add;
        add = ((a.num[i] & 1) * 5);
        a.num[i] = digit;
    }
    while (a.num.size() > 1 && !a.num.back())
        a.num.pop_back();
}

// Friend function to calculate the factorial of an integer
BigInt getFactorial(int n) {
    BigInt f(1);
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

// Friend function to output BigInt to the stream
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--)
        cout << (short)a.num[i];
    return cout;
}

int main() {
    for (int i = 0; i <= 100; i++) {
        BigInt fact;
        fact = getFactorial(i);
        cout << "Factorial of " << i << " = ";
        cout << fact << '\n';
    }
}

/*
BigInt is a custom class designed to handle large integers represented as strings of digits.

It includes various member functions and overloaded operators to perform arithmetic operations and manipulate BigInt objects.

The getFactorial function calculates and returns the factorial of an integer using BigInt objects.

The main function demonstrates the use of the BigInt class by calculating and printing the factorial of integers from 0 to 100.

The Null function checks if a BigInt is zero by examining its size and contents.

*/
