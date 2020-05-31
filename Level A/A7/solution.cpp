#include <iostream>

typedef long long ll;

ll extendedGCD(ll a, ll b, ll &x, ll &y);

int main()
{
    int t(0);
    std::cin >> t;
    do
    {
        ll A(0), B(0), x(0), y(0);
        std::cin >> A >> B;
        ll d = extendedGCD(A, B, x, y);
        printf("%lld %lld %lld %lld %lld\n", x, y, x - B, y + A, d);
    } while (--t);

    return 0;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll tp = extendedGCD(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * x;
    return tp;
}