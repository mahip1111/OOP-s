#include <iostream>
using namespace std;

class MyClass {       
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}

// Q:- HOW DATA TYPES ARE INITIALIZED IN C++:
// ANS:-
// Golden Rule (Interview Rule ⭐)

// Built-in types
// int
// char
// float
// bool
// double
// pointer

// 👉 Constructor nahi hota.
// 👉 Default value nahi milti.
// 👉 Garbage/Indeterminate value.

// Class types
// string
// vector
// map
// set
// queue
// stack

// 👉 Constructor automatically call hota hai.
// 👉 Object valid state me hota hai.
// 👉 string → empty string
// 👉 vector → empty vector
// 👉 map → empty map