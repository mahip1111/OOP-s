#include <iostream>
using namespace std;

class Animal {

protected:
    string name;

public:

    Animal() {
        name = "Dog";
    }

};

class Pet : public Animal {

public:

    void display() {

        cout << name;

    }

};

int main() {

    Pet p;

    p.display();

}