//Ссылка на задачу: 
//https://codeforces.com/contest/337/problem/B

#include <iostream>

using std::cin;

long long binaryGCD(long long, long long);

int main()
{
    long long a(0), b(0), c(0), d(0), answer(0);
    cin >> a >> b >> c >> d;
    if (a * d == c * b)
        printf("0");
    else
    {
        long long gcd(0);
        if (a * d > c * b) // заполнит всю высоту
        {
            gcd = binaryGCD((a * d - b * c), a * d);
            printf("%lld/%lld", (a * d - b * c) / gcd, (a * d) / gcd);
        }
        else // заполнит всю ширину
        {
            gcd = binaryGCD((c * b - a * d), c * b);
            printf("%lld/%lld", (b * c - a * d) / gcd, (b * c) / gcd);
        }
    }
    return 0;
}

long long binaryGCD(long long a, long long b)
{
    if (a < 0)
        a = ~a + 1;
    if (b < 0)
        b = ~b + 1;
    long long cnt2(1);
    while (a && b)
    {
        while (!(a & 1) && !(b & 1))
        {
            a >>= 1;
            b >>= 1;
            cnt2 *= 2;
        }
        while (!(a & 1))
            a >>= 1;
        while (!(b & 1))
            b >>= 1;
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    if (!a)
        return b * cnt2;
    else
        return a * cnt2;
}
