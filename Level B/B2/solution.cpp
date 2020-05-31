// https://codeforces.com/problemset/problem/1034/A

#include <math.h>
#include <iostream>

#define MN 300000
#define MX 15000000

int gcd(int x, int y);

int least_prime_div[MX + 5] = {0}, primes[MX + 5] = {0}, pnum(0), s[MX + 5] = {0};

int main()
{
	int num(0), allgcd(0), curdiv(0), ans(0), input[MN + 5] = {0};

	// Поиск простых чисел и чисел, которые на них делятся
	for (int i = 2; i <= MX; ++i)
	{
		if (!least_prime_div[i])
			least_prime_div[i] = primes[++pnum] = i;
		for (int j = 1; i * primes[j] <= MX; ++j)
		{
			least_prime_div[i * primes[j]] = primes[j];
			if (i % primes[j] == 0)
				break;
		}
	}

	// Ввод и нахождение НОД
	std::cin >> num;
	for (int i = 1; i <= num; ++i)
	{
		std::cin >> input[i];
		allgcd = gcd(allgcd, input[i]);
	}

	// Подсчет, сколько раз каждое простое число
	// оказалось минимальным делителем для
	// чисел из введенного набора, сокращенных на НОД.
	for (int i = 1; i <= num; ++i)
		for (int j = input[i] / allgcd; j > 1;)
		{
			curdiv = least_prime_div[j];
			s[curdiv]++;
			do
				j /= least_prime_div[j];
			while (least_prime_div[j] == curdiv);
		}
	for (int i = 1; i <= MX; ++i)
		ans = fmax(ans, s[i]);
	printf("%d", ans ? num - ans : -1);
	return 0;
}

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}