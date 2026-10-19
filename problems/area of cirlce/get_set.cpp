#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    float getRadius() {
        return radius;
    }
};

int main() {
    Circle c;
    c.setRadius(5);

    float area = 3.14 * c.getRadius() * c.getRadius();
    cout << area;
}