/*
Create and use one pointer to print the values of different data types.
*/
#include <iostream>

int main() {
    int number = 10;
    float pi = 3.14;
    char letter = 'A';

    void* ptr;

    ptr = &number;
    std::cout << "Value of number: " << *(int*)ptr << std::endl;

    ptr = &pi;
    std::cout << "Value of pi: " << *(float*)ptr << std::endl;

    ptr = &letter;
    std::cout << "Value of letter: " << *(char*)ptr << std::endl;

    return 0;
}

/*
In this program, a void pointer ptr is created. \
It is then assigned the addresses of number, pi, and letter variables, respectively.
The program casts the void pointer to the appropriate data type before dereferencing it to print the values.
*/
