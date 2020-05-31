#include <iostream>
#include <string>

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
  for (int i = 0; i < t; ++i)
  {
    std::string num;
    std::cin >> num;
    int len = num.size();
    currGCD = GCD( currGCD, len );
  }
  std::cout << currGCD;

  return 0;
}