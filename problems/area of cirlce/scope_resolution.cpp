#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    void input();   // Function declaration
    void area();    // Function declaration
};

// Function definition outside the class
void Circle::input() {
    cout << "Enter radius: ";
    cin >> radius;
}

// Function definition outside the class
void Circle::area() {
    float a = 3.14159 * radius * radius;
    cout << "Area of Circle = " << a << endl;
}

int main() {
    Circle c;

    c.input();
    c.area();

    return 0;
}