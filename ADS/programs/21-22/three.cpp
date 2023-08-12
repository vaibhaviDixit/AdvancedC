/*
 Create a class called 'Array' with attributes 'size' and 'data'.
 Implement a copy assignment operator to copy the contents of one array to another.

 Input:
  Array arr1(5);
  arr1 = Array(5);

  Array arr2(3);
  arr2 = arr1;

  arr1.display();
  arr2.display();

 Output:
 15770936 15728832 0 10696 248
 15770936 15728832 0 10696 248



*/

#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int* data;

public:
    Array(int s) {
        size = s;
        data = new int[size];
    }

    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    Array arr1(5);
    arr1 = Array(5); // Copy assignment operator called

    Array arr2(3);
    arr2 = arr1; // Copy assignment operator called

    arr1.display();
    arr2.display();

    return 0;
}

/*
In this C++ program, we define a class Array to represent an array of integers with private attributes size and data. The class has a constructor that takes a parameter s (size) to initialize the size attribute and dynamically allocates memory for the array using new int[size].

The Array class also has a copy constructor, which is used to create a new object as a copy of an existing Array object. The copy constructor takes a reference to another Array object (const Array& other) as its parameter. Inside the copy constructor, we allocate new memory for the array and copy the elements from the data array of the other object to initialize the data array of the newly created object.

Additionally, the class has a copy assignment operator (operator=) that allows assignment of one Array object to another. The copy assignment operator takes a reference to another Array object (const Array& other) as its parameter. It first checks whether the two objects are not the same (to avoid self-assignment) and then deallocates the current data array using delete[] and allocates new memory for the data array. Next, it copies the elements from the data array of the other object to the data array of the current object.

The Array class also has a member function display() that prints the elements of the array to the console.

In the main() function, we create two Array objects arr1 and arr2 using the constructor. Then, we use the copy assignment operator to assign a new Array object (created using Array(5)) to arr1. This will call the copy assignment operator and create a deep copy of the object.

Next, we use the copy assignment operator again to assign arr1 to arr2. This will also create a deep copy of the object.

Finally, we call the display() function on both arr1 and arr2 to print their elements to the console.

*/




