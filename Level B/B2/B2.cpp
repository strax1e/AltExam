// https://codeforces.com/problemset/problem/1349/A

#include <iostream>

const int maxn = 100005;

long long gcd(long long x, long long y);

int main()
{
	int n;
	long long ga(0), ans(0), pre[maxn] = {0}, suf[maxn] = {0}, a[maxn] = {0};
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	pre[1] = a[1];
	suf[n] = a[n];

	// Creating and computing gcd of set d_i = {a_j | j != i}
	for (int i = 2; i <= n; i++)
		pre[i] = gcd(pre[i - 1], a[i]);
	for (int i = n - 1; i >= 1; i--)
		suf[i] = gcd(suf[i + 1], a[i]);
	for (int i = 0; i < n; i++)
		if (!i)
			ans = suf[2];
		else if (i == n - 1)
			ans = ans * pre[n - 1] / gcd(pre[n - 1], ans);
		else
			ans = ans * gcd(pre[i], suf[i + 2]) / gcd(gcd(pre[i], suf[i + 2]), ans);
	printf("%lld\n", ans);
	return 0;
}

long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}