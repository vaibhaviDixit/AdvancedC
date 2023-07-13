/*
Check if a pointer is null before dereferencing it.
*/

#include <iostream>

int main() {
    int* ptr = NULL;

    if (ptr != NULL) {
        *ptr = 10; // Dereferencing the pointer
    } else {
        std::cout << "Pointer is null!" << std::endl;
    }

    return 0;
}

/*
This program showcases the usage of null pointers. It initializes ptr as a null pointer using NULL.
It then checks if ptr is not null before attempting to dereference it.
Since it is indeed a null pointer, it prints a message instead of dereferencing.
*/
