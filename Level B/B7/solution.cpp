#include <iostream>

int gcd(int x, int y);

void exgcd(int a, long long &x, int b, long long &y);

int main()
{
    int n, m, x, y, vx, vy, a, b, c;
    long long xx, yy;
    std::cin >> n >> m >> x >> y >> vx >> vy;
    if (x == 0 && (y == 0 || y == m) || x == n && (y == 0 || y == m))
    {
        printf("%d %d\n", x, y);
        return 0;
    }
    if (vx == 0 && vy == 0)
    {
        printf("-1\n");
        return 0;
    }
    if (vx == 0)
    {
        if (x == 0 || x == n)
            printf("%d %d\n", x, vy == 1 ? m : 0);
        else
            printf("-1\n");
        return 0;
    }
    if (vy == 0)
    {
        if (y == 0 || y == m)
            printf("%d %d\n", vx == 1 ? n : 0, y);
        else
            printf("-1\n");
        return 0;
    }
    a = n, b = m, c = (vy < 0 ? y : m - y) - (vx < 0 ? x : n - x);
    int d = gcd(a, b);
    if (c % d != 0)
    {
        printf("-1\n");
        return 0;
    }
    exgcd(a, xx, b, yy);
    xx *= c / d, yy *= c / d;
    xx = (xx % (b / d) + (b / d)) % (b / d), yy = (xx * a - c) / b;
    if ((vx > 0) == (xx % 2))
        printf("0 ");
    else
        printf("%d ", n);
    if ((vy > 0) == (yy % 2))
        printf("0\n");
    else
        printf("%d\n", m);
    return 0;
}

int gcd(int x, int y)
{
    if (!y)
        return x;
    else
        return gcd(y, x % y);
}

void exgcd(int a, long long &x, int b, long long &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return;
    }
    exgcd(b, x, a % b, y);
    int t = y;
    y = x - a / b * y, x = t;
}