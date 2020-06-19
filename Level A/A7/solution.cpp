// https://acmp.ru/index.asp?main=task&id_task=527

#include <iostream>
typedef long long LL;

// ф-ция, возвращающая true, если условие задачи выполняется, иначе - false
bool customGCD( LL a, LL b, LL c, LL d )
{
  // проверка на совпадение до какой-либо обработки переменных
  if (a == c && b == d)
    return true;

  // проверка на совпадения будет выполняться, пока не найден НОД
  while (b)
  {
    if (b > a)
    {
      // обмен значений переменных a и b
      LL tmp = a;
      a = b;
      b = tmp;

      // проверка на совпадение
      if (a == c && b == d)
        return true;
    }

    // b > 0, для того чтобы далее не производилось деление на нуль
    if (b > 0)
    {
      // сохранение старого значения переменной a
      LL oldA = a;
      // для ускорения алгоритма, вычитаем из a сразу максимальное кол-во раз значение b
      a %= b;

      // проверка на совпадение: с должно обязательно лежать в пределах [a, oldA]
      // разница между oldA и c должна делиться на вычитаемое число, то есть на b
      if (b == d && a <= c && c <= oldA && !((oldA - c) % b))
        return true;
    }
  }

  // совпадений не найдено
  return false;
}


int main()
{
  LL k, a, b, c, d;
  std::cin >> k;

  // обработка k наборов
  for (LL i = 0; i < k; ++i)
  {
    std::cin >> a >> b >> c >> d;
    if (customGCD( a, b, c, d ))
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }

  return 0;
}