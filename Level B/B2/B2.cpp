#include <iostream>

int main()
{
    long long a(0), b(0), k(0);
    std::cin >> a >> b;
    while (a && b)
    {
        if (a < b)
        {
            k += b / a;
            b %= a;
        }
        else
        {
            k += a / b;
            a %= b;
        }
    }
    std::cout << k;
    return 0;
}