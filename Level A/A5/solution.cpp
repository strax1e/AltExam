#include <iostream>

typedef long long ll;

ll extendedGCD(ll a, ll b, ll &x, ll &y);

int main()
{
    int T(0);
    std::cin >> T;
    do
    {
        ll Q(0), E(0), R(0), x(0), y(0);
        std::cin >> Q >> E >> R;
        ll d = extendedGCD(Q, E, x, y);
        if (R % d)
            puts("NO\n");
        else
        {
            x *= R / d;
            y *= -(R / d);
            E /= d;
            Q /= d;
            while (x < 0 || y < 0)
            {
                x += E;
                y += Q;
            }
            printf("%lld %lld\n", x, y);
        }
    } while (--T);
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
