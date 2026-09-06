#include <iostream>
using namespace std;

// Parent
class Animal
{
public:
    string name;

    void eat()
    {
        cout << name << " is eating\n";
    }

    void sleep()
    {
        cout << name << " is sleeping\n";
    }
};

// Single + Multilevel
class Dog : public Animal
{
public:
    void bark()
    {
        cout << name << " is barking\n";
    }
};

// Multilevel
class Puppy : public Dog
{
public:
    void weep()
    {
        cout << name << " is weeping\n";
    }
};

// Hierarchical
class Cat : public Animal
{
public:
    void meow()
    {
        cout << name << " says meow\n";
    }
};

// Multiple Inheritance
class FlyingAnimal
{
public:
    void fly()
    {
        cout << "Flying\n";
    }
};

class Bat : public Animal, public FlyingAnimal
{

};

int main()
{
    cout << "------ Single Inheritance ------\n";

    Dog d;
    d.name = "Tommy";
    d.eat();
    d.bark();

    cout << "\n------ Multilevel Inheritance ------\n";

    Puppy p;
    p.name = "Bruno";
    p.eat();
    p.bark();
    p.weep();

    cout << "\n------ Hierarchical Inheritance ------\n";

    Cat c;
    c.name = "Kitty";
    c.eat();
    c.meow();

    cout << "\n------ Multiple Inheritance ------\n";

    Bat b;
    b.name = "Batman";
    b.eat();
    b.fly();
}