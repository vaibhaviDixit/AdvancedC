/*
Perform pointer arithmetic on a void pointer.
*/

#include <iostream>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    void* ptr = numbers;

    int* intPtr = static_cast<int*>(ptr); //cast void pointer to int

    std::cout << "First element: " << *intPtr << std::endl;
    std::cout << "Third element: " << *(intPtr + 2) << std::endl;

    return 0;
}

/*
 This program demonstrates performing pointer arithmetic on a void pointer.
 The ptr is initially assigned the address of the numbers array.
 It is then cast to an int pointer using static_cast.
 The program dereferences the pointer and also accesses the third element of the array using pointer arithmetic
*/
