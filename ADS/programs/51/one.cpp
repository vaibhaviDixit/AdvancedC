/*
Write a C++ program for getting huge Fibonacci number using a big integer data type

Input: 91
Output:  4660046610375530309

Input: 77
Output:  5527939700884757


*/

#include <bits/stdc++.h>
using namespace std;

class BigInt {
    string num; // Stores a large integer as a string of digits
public:
    BigInt(unsigned long long n = 0); // Constructor to initialize with an unsigned long long
    BigInt(BigInt &); // Copy constructor
    friend void divideByTwo(BigInt &a); // Friend function to divide the BigInt by 2
    friend int Length(const BigInt &); // Friend function to get the length of the BigInt
    BigInt &operator=(const BigInt &); // Assignment operator overload
    friend BigInt &operator+=(BigInt &, const BigInt &); // Friend function to add BigInts in-place
    friend ostream &operator<<(ostream &, const BigInt &); // Friend function to output BigInt to stream
    friend BigInt getNthFibNum(int n); // Friend function to calculate the nth Fibonacci number
};

// Constructor to initialize a BigInt with an unsigned long long
BigInt::BigInt(unsigned long long nr) {
    do {
        num.push_back(nr % 10); // Extract the last digit and add it to the string
        nr /= 10; // Remove the last digit from the number
    } while (nr);
}

// Copy constructor
BigInt::BigInt(BigInt &a) {
    num = a.num;
}

// Friend function to get the length of the BigInt
int Length(const BigInt &a) {
    return a.num.size();
}

// Assignment operator overload
BigInt &BigInt::operator=(const BigInt &a) {
    num = a.num;
    return *this;
}

// Friend function to add BigInts in-place
BigInt &operator+=(BigInt &a, const BigInt &b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.num.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.num[i] + b.num[i]) + t;
        else
            s = a.num[i] + t;
        t = s / 10;
        a.num[i] = (s % 10);
    }
    if (t)
        a.num.push_back(t);
    return a;
}

// Friend function to add two BigInts and return a new BigInt
BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
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

// Friend function to calculate the nth Fibonacci number
BigInt getNthFibNum(int n) {
    BigInt a(1), b(1), c;
    if (!n)
        return c;
    n--;
    while (n--) {
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

// Friend function to output BigInt to the stream
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--)
        cout << (short)a.num[i];
    return cout;
}

int main() {
    for (int i = 0; i <= 100; i++) {
        BigInt Fib;
        Fib = getNthFibNum(i);
        cout << "Fibonacci number at " << i << " = " << Fib << '\n';
    }
}

/*

BigInt is a custom class designed to handle large integers represented as strings of digits.

It includes various member functions and overloaded operators to perform arithmetic operations and manipulate BigInt objects.

The getNthFibNum function calculates and returns the nth Fibonacci number using BigInt objects.

The main function demonstrates the use of the BigInt class by calculating and printing the first 101 Fibonacci numbers.

*/


