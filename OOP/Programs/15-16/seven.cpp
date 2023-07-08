/*
 C++ program to find maximum and minimum of two numbers without using loop and any condition.

Input: 17 19
Output: max = 19
        min = 17
*/

#include<iostream>
#include <cstdlib> //header file for abs() method

using namespace std;
int main ()
{
    int a,b;
    cin>>a>>b;

    int maxi=((a + b) + abs(a - b)) / 2;
    int mini=((a + b) - abs(a - b)) / 2;

    cout<<"max = "<< maxi<<endl;
    cout<<"min = "<<mini;
    return 0;
}
