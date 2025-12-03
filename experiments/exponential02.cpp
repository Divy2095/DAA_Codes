#include <bits/stdc++.h>
using namespace std;

double exponential(double base, int power)
{
    if (power == 0)
        return 1;
    if (power < 0)
        return 1 / exponential(base, -power);
    return base * exponential(base, power - 1);
}

int main()
{
    double base;
    cout << "Enter number: ";
    cin >> base;
    double power;
    cout << "Enter exponent: ";
    cin >> power;
    double expo = exponential(base, power);
    cout << expo << endl;
    return 0;
}