/*
C++ program to check if two numbers are equal without using arithmetic operators comparison operators

Input: 5 5
Output: x is equal to y

*/
#include <iostream>
using namespace std;

int main()
{
    int x;
    int y;

    cin>>x>>y;

    if (!(x ^ y))
        cout << " x is equal to y ";
    else
        cout << " x is not equal to y ";

    return 0;
}

