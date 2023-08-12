/*
Create a class called 'StringWrapper' to manage a dynamic string.
Implement constructors, copy constructor, copy assignment operator, and destructor to manage deep copy.

Input:
    StringWrapper str1("Hello");
    StringWrapper str2 = str1; // Copy constructor called
    StringWrapper str3;

    str3 = str1; // Copy assignment operator called

    str1.display();
    str2.display();
    str3.display();

Output:
Hello
Hello
Hello

*/

#include <iostream>
#include <cstring>
using namespace std;

class StringWrapper {
private:
    char* str;

public:
    StringWrapper(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    StringWrapper(const StringWrapper& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void display() {
        cout << str << endl;
    }

    ~StringWrapper() {
        delete[] str;
    }
};

int main() {
    StringWrapper str1("Hello");
    StringWrapper str2 = str1; // Copy constructor called
    StringWrapper str3;

    str3 = str1; // Copy assignment operator called

    str1.display();
    str2.display();
    str3.display();

    return 0;
}

/*
The StringWrapper class has the following member functions:

Constructor: The constructor takes a const char* s as its parameter and initializes the str attribute. It allocates memory for the character array using new char[strlen(s) + 1] and copies the contents of the input C-string s into the str attribute using strcpy.

Copy Constructor: The copy constructor is used to create a new StringWrapper object as a copy of an existing StringWrapper object. It takes a reference to another StringWrapper object (const StringWrapper& other) as its parameter. Inside the copy constructor, we create a deep copy of the str attribute by allocating new memory for the character array and copying the characters from the other object's str attribute using strcpy.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one StringWrapper object to another. It takes a reference to another StringWrapper object (const StringWrapper& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment) and then deallocates the current memory using delete[]. Next, it updates the str attribute with a deep copy of the str attribute from the other object. It allocates new memory for the character array and copies the characters from the other object's str attribute using strcpy.

display function: This function is used to display the contents of the str attribute to the console.

Destructor: The destructor is responsible for releasing the dynamically allocated memory when the object is destroyed. It uses delete[] to deallocate the memory assigned to the character array.

In the main() function, we demonstrate the use of the StringWrapper class by creating three StringWrapper objects (str1, str2, and str3). We initialize str1 with the C-string "Hello". Then, we create str2 as a copy of str1 using the copy constructor, and str3 without any initialization. We then use the copy assignment operator to assign str1 to str3. Finally, we display the contents of all three objects using the display() function.

*/


