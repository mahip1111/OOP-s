#include "Car.h"
#include <iostream>
using namespace std;

void Car::start()
{
    cout << "Car Started";
}

void Car::stop()
{
    cout << "Car Stopped";
}

int Car::speed(int maxSpeed)
{
    return maxSpeed;
}