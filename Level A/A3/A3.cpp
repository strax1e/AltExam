// https://codeforces.com/problemset/problem/822/A

#include <iostream>
#include <algorithm>

int main()
{
    int a, b, ans = 1;
    std::cin >> a >> b;
    for (int i = 2; i <= std::min(a, b); ++i)
        ans *= i;
    std::cout << ans;
    return 0;
}
