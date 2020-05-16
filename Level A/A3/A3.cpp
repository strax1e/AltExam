/* https://codeforces.com/problemset/problem/822/A
 *
 * Данная задача даёт понять, что не нужно бросаться реализовывать
 * первый алгоритм, который пришел в голову. Стоит аккуратно оценить
 * ограничения вводимых данных и придумать рациональное решение.
 */

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
