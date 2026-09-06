#include <iostream>
using namespace std;

class Student
{
public:
    int *marks;

    Student()
    {
        marks = new int(95);
    }

    ~Student()
    {
        delete marks;
    }
};

int main()
{
    Student s1;
    Student s2 = s1;
}

// What is wrong with this code?

// Expected answer:

// Compiler-generated copy constructor performs shallow copy. Both objects point to the same heap memory. Both destructors call delete on the same address, causing double deletion and undefined behavior.