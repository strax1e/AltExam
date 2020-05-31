// https://codeforces.com/contest/585/problem/C

#include <iostream>

long long GCD(long long, long long);

int main()
{
    long long x(0), y(0);
    std::cin >> x >> y;
    if (GCD(x, y) == 1)
        while (x && y)
        {
            if (y < x)
            {
                long long tmp = x / y;
                x %= y;
                if (!x)
                    --tmp;
                printf("%lldA", tmp);
            }
            else
            {
                long long tmp = y / x;
                y %= x;
                if (!y)
                    --tmp;
                printf("%lldB", tmp);
            }
        }
    else
        printf("Impossible");
    return 0;
}

long long GCD(long long a, long long b)
{
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
