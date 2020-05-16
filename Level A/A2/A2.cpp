/* https://codeforces.com/problemset/problem/664/A
 *
 * Данная задача заставляет студентов задуматься о том,
 * что не стоит бояться пугающих на первый взгляд условий,
 * стоит лишь немного подумать.
 */

#include <iostream>
#include <string>

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    if (a == b)
        std::cout << a;
    else
        std::cout << 1;

    return 0;
}