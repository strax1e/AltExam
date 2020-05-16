// https://codeforces.com/problemset/problem/798/C

#include <iostream>

int gcd(int a, int b)
{
  while (b)
  {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main()
{
  int n, elem, ans = 0, currGCD = 0, countOdd = 0;
  std::cin >> n;

  for (int i = 0; i < n; ++i)
  {
    std::cin >> elem;
    currGCD = gcd(elem, currGCD);

    if (elem % 2)
      ++countOdd;
    else
    {
      ans += countOdd / 2 + countOdd % 2 * 2;
      countOdd = 0;
    }
  }

  ans += countOdd / 2 + countOdd % 2 * 2;

  std::cout << "YES\n";
  if (currGCD == 1)
    std::cout << ans;
  else
    std::cout << 0;

  return 0;
}