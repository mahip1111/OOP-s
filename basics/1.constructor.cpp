// A constructor is a special member function of a class that is automatically invoked(called/executed) when an object is created to initialize the object.

#include <iostream>
using namespace std;

class Student
{
public:

    Student()
    {
        cout << "Object Created";
    }
};

int main() {
    Student s1; // Object of class Student
    return 0;
}

//constructor don't have the return type, not even void. It has the same name as the class. It is automatically called when an object is created. It is used to initialize the object.

// constructor can be overloaded. If we don't define a constructor, the compiler provides a default constructor. If we define a constructor, the compiler does not provide a default constructor.

// costructor runs only once when the object is created. It cannot be called explicitly. It is used to initialize the object. It can have parameters. It can be defined inside or outside the class. It can be defined as public, private or protected. It can be defined as default, parameterized or copy constructor.