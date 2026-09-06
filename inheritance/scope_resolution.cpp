#include <iostream>
using namespace std;

class Car {
  public:
    int speed(int maxSpeed);
};

int Car::speed(int maxSpeed) {
  return maxSpeed;
}

int main() {
  Car myObj;
  cout << myObj.speed(200);
  return 0;
}

// The code here does:

// 1. Declare the function inside the class.
// 2. Define it outside using Car::speed().

// This separation is common in larger projects because it keeps the class definition clean. Often, the declaration goes in a header file (.h) and the definition goes in a source file (.cpp).