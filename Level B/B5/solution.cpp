// https://codeforces.com/problemset/problem/798/C

#include <iostream>

// алгоритм нахождения НОД
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

  // обработка последовательности длины n
  for (int i = 0; i < n; ++i)
  {
    std::cin >> elem;
    // нахождение НОД для уже обработанных чисел и одного нового
    currGCD = gcd(elem, currGCD);

    // подсчет количества нечетных чисел в одной подпоследовательности
    if (elem % 2)
      ++countOdd;
    // обновление ответа при встрече четного числа
    else
    {
      ans += countOdd / 2 + countOdd % 2 * 2;
      countOdd = 0;
    }
  }
  // обновление ответа при достижении конца последовательности
  ans += countOdd / 2 + countOdd % 2 * 2;

  std::cout << "YES\n";
  
  // проверка на то, что НОД последовательности изначально был равен 1
  if (currGCD == 1)
    std::cout << ans;
  else
    std::cout << 0;

  return 0;
}