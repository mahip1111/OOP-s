#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int age;

    // Default Constructor
    Student()
    {
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Student(string name, int age)
    {
        cout << "Parameterized Constructor Called" << endl;

        this->name = name;
        this->age = age;
    }

    // Copy Constructor
    Student(const Student &other)
    {
        cout << "Copy Constructor Called" << endl;

        this->name = other.name;
        this->age = other.age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }

    ~Student()
    {
        cout << "Destructor Called for " << name << endl;
    }
};

int main()
{
    cout << "Creating s1\n\n";

    Student s1("Rahul",20);

    cout << "\nDisplaying s1\n";
    s1.display();

    cout << "\nCreating s2 from s1\n\n";

    Student s2 = s1;

    cout << "\nDisplaying s2\n";
    s2.display();

    cout << "\nChanging s2\n";

    s2.name = "Aman";
    s2.age = 25;

    cout << "\nDisplaying s1\n";
    s1.display();

    cout << "\nDisplaying s2\n";
    s2.display();

    cout << "\nEnd of Program\n";
}