#include <iostream>
using namespace std;

class Number
{
private:
    int number;

public:
    void input();
    void prime();
    void odd_or_even();
    void factorial();
};

// Function Definitions

void Number::input()
{
    cout << "Enter a number: ";
    cin >> number;
}

void Number::prime()
{
    bool prime = true;

    if (number <= 1)
    {
        prime = false;
    }
    else
    {
        for (int i = 2; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                prime = false;
                break;
            }
        }
    }

    if (prime)
        cout << "Prime Number" << endl;
    else
        cout << "Not Prime Number" << endl;
}

void Number::odd_or_even()
{
    if (number % 2 == 0)
        cout << "Even Number" << endl;
    else
        cout << "Odd Number" << endl;
}

void Number::factorial()
{
    long long fact = 1;

    for (int i = 1; i <= number; i++)
    {
        fact = fact * i;
    }

    cout << "Factorial = " << fact << endl;
}

int main()
{
    Number N1;

    N1.input();
    N1.prime();
    N1.odd_or_even();
    N1.factorial();

    return 0;
}