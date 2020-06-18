#include <iostream>
#include <string>

// алгоритм нахождения НОД
int GCD( int a, int b )
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
  int t;
  std::cin >> t;
  int currGCD = 0;

  // обработка t чисел
  for (int i = 0; i < t; ++i)
  {
    std::string num;
    std::cin >> num;
    // получения размера (длины) числа
    int len = num.size();
    // нахождение НОД для уже обработанных чисел и одного нового
    currGCD = GCD( currGCD, len );
  }
  std::cout << currGCD;

  return 0;
}