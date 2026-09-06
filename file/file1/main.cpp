#include "Car.h"
#include <iostream>
using namespace std;

int main()
{
    Car c;

    c.start();
    cout << c.speed(200);

    return 0;
}