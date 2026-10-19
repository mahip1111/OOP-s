#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    void input() {
        cin >> radius;
    }

    friend void area(Circle);
};

void area(Circle c) {
    cout << "Area = " << 3.14 * c.radius * c.radius;
}

int main() {
    Circle c;
    c.input();
    area(c);
}