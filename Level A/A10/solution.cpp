#include <iostream>

// Eucledean alghorythm. Subtraction
int gcd( int A, int B, int &N )
{
  while (A != B)
  {
    N++; // counting iterations
    if (A > B)
      A -= B;
    else 
      B -= A;
  }
  return A;
}
int N[100], D[100];

int main( void )
{
  int A, B, T;
  std::cin >> T;
  for (int i = 0; i < T; i++)
  {
    std::cin >> A;
    std::cin >> B;
    D[i] = A * B / gcd(A, B, N[i]);
  }
  for (int i = 0; i < T; i++)
    std::cout << D[i] << " " << N[i] << std::endl;
  return 0;
}