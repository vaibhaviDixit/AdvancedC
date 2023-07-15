/*
 Implement a base class "Base" and two derived classes "A" and "B."
 Add a static member variable to "Base" and demonstrate its use in "A" and "B."

*/

#include <iostream>
using namespace std;

class Base {
public:
    static int staticVar;

    Base() {
        staticVar++;
    }
};

int Base::staticVar = 0;

class A : public Base {
public:
    A() : Base() {}
};

class B : public Base {
public:
    B() : Base() {}
};

int main() {
    A objA1;
    A objA2;
    B objB1;
    B objB2;

    cout << "Static Variable Value: " << Base::staticVar << endl;

    return 0;
}
