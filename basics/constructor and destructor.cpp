// constructorand destructor
#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name;
        int age;

        Student(){
            cout<<"Student constructor is called\n";
        }

        void sleep(){
            cout<<this->name<<" is sleeping\n";
        }
        ~Student(){
            cout<<this->name<<" destructor is called\n";
        }
};

int main(){
    Student s1;
    s1.name = "Rahul";
    s1.sleep();
    Student s2;
    s2.name = "Shivam";
    s2.sleep();
}

//Output:

// Student constructor is called
// Rahul is sleeping
// Student constructor is called
// Shivam is sleeping
// Shivam destructor is called
// Rahul destructor is called

// here observe that destructor follow the reverse order of the calling (LIFO).