#define _CRT_SECURE_NO_WARNINGS

/* Ссылка на задачу:
 * https://codeforces.com/problemset/problem/1034/A 
 */

#include <math.h>
#include <stdio.h>

#define MN 300000
#define MX 15000000
int input[MN + 5], least_prime_div[MX + 5], primes[MX + 5], pnum = 0, s[MX + 5];

int gcd( int x,int y )
{
	return y ? gcd(y, x % y) : x;
}

int main( void )
{
	int num, allgcd = 0, curdiv, ans = 0;
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
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i)
	{
		scanf("%d", &input[i]);
		allgcd = gcd(allgcd, input[i]);
	}
	/* Подсчет сколько раз каждое простое число 
	 * оказалось минимальным делителем для
	 * чисел из введенного набора, сокращенных на НОД
	 */
	for (int i = 1; i <= num; ++i)
		for (int j = input[i] / allgcd; j > 1;)
		{
			curdiv = least_prime_div[j];
			s[curdiv]++;
			do
			{
		   	j /= least_prime_div[j];
			} while (least_prime_div[j] == curdiv);
		}
	for (int i = 1; i <= MX; ++i)
		ans = fmax(ans, s[i]);
	printf("%d", ans ? num - ans : -1);
	return 0;
}