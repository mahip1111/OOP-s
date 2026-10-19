#include <iostream>
using namespace std;

class Parent {
protected:
    int number = 100;
};

class Child : private Parent {    // in this case the type of inheritance don't matter on the result reason you can read the comments below
public:
    void show() {
        cout << number;
    }
};

int main() {

    Child obj;

    obj.show();

    return 0;
}

// output: 100

// but if the member 'number' was declared as private in the Parent class, it would not be accessible in the Child class, and trying to access it would result in a compilation error.


// how properties work differently based on the type of inheritance:

// Agar inheritance type public hai:
// class Child : public Parent
// toh Parent ke members ka result:

// Parent member     →     Child mein
// public            →     public
// protected         →     protected
// private           →     inaccessible


// Agar inheritance type protected:
// class Child : protected Parent

// Parent member     →     Child mein
// public            →     protected
// protected         →     protected
// private           →     inaccessible


// Agar inheritance type private:
// class Child : private Parent

// Parent member     →     Child mein
// public            →     private
// protected         →     private
// private           →     inaccessible