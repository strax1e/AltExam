// https://acmp.ru/index.asp?main=task&id_task=384

#include <iostream>
#define BLN 1000000000

// алгоритм нахождения НОД
int gcd( int a, int b )
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
  int i, j, g;
  std::cin >> i >> j;
  // нахождение НОД двух индексов чисел Фибоначчи
  g = gcd( i, j );

  int f0 = 0, f1 = 1, ftmp = 1;
  // нахождение g-ого числа Фибоначчи
  for (int i = 2; i <= g; ++i)
  {
    ftmp = (f0 + f1) % BLN;
    f0 = f1;
    f1 = ftmp;
  }

  // вывод g-ого числа Фибоначчи
  std::cout << ftmp;

  return 0;
}