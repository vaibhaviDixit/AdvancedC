/*
 Write C++ program to print maximum value of unsigned int.
*/

#include <iostream>

int main()
{
    unsigned int max;
    max = 0;
    max = ~max;

    std::cout << "Max value : " << max;

    return 0;
}

