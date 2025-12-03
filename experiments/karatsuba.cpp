#include <bits/stdc++.h>
using namespace std;
long long karatsuba(long long x, long long y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }
    int m = max(to_string(x).length(), to_string(y).length());
    long long m2 = m / 2;
    long long power = pow(10, m2);

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ab_cd = karatsuba(a + b, c + d) - ac - bd;

    return (ac * pow(10, m)) + (ab_cd * pow(10, m2)) + bd;
}
int main()
{
    long long x, y;
    cout << "Enter first number";
    cin >> x;
    cout << "Enter second number";
    cin >> y;
    string result = to_string(karatsuba(x, y));
    cout << x << "*" << y << "=" << result;
    cout << "\n";
    return 0;
}
