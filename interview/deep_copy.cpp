// Deep Copy creates a separate copy of dynamically allocated memory. Instead of copying only the pointer, it allocates new memory and copies the actual data. This ensures that each object owns its own resources, preventing shared modifications and double deletion.

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int *marks;

    // Parameterized Constructor
    Student(string name, int marks)
    {
        cout << "Parameterized Constructor Called\n";

        this->name = name;

        this->marks = new int;
        *(this->marks) = marks;
    }

    // Deep Copy Constructor
    Student(const Student &other)
    {
        cout << "Deep Copy Constructor Called\n";

        name = other.name;

        // Allocate New Heap Memory
        marks = new int;

        // Copy Value
        *marks = *other.marks;
    }

    void display()
    {
        cout << "Name  : " << name << endl;
        cout << "Marks : " << *marks << endl;
        cout << "Address Stored in Pointer : " << marks << endl;
        cout << endl;
    }

    ~Student()
    {
        cout << "Destructor Called for " << name << endl;

        delete marks;
    }
};

int main()
{
    Student s1("Rahul",95);

    cout << "\n----------- s1 -----------\n";
    s1.display();

    Student s2 = s1;

    cout << "\n----------- After Copy -----------\n";
    s1.display();
    s2.display();

    cout << "Changing s2 Marks...\n\n";

    *s2.marks = 10;

    cout << "----------- s1 -----------\n";
    s1.display();

    cout << "----------- s2 -----------\n";
    s2.display();
}

//Output:

// Parameterized Constructor Called

// ----------- s1 -----------
// Name : Rahul
// Marks : 95
// Address : 0x61ff08

// Deep Copy Constructor Called

// ----------- After Copy -----------

// Name : Rahul
// Marks : 95
// Address : 0x61ff08

// Name : Rahul
// Marks : 95
// Address : 0x61ff30

// Changing s2 Marks...

// ----------- s1 -----------

// Name : Rahul
// Marks : 95
// Address : 0x61ff08

// ----------- s2 -----------

// Name : Rahul
// Marks : 10
// Address : 0x61ff30
