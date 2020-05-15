// https://codeforces.com/problemset/problem/1349/A
/* Задача, требующая предварительной теоретической обработки условия */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

const int maxn = 100005;

int n;
long long a[maxn];

long long pre[maxn],suf[maxn];

long long gcd( long long x, long long y )
{
  return y ? gcd(y, x % y) : x;
}

long long ga, ans;

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) 
    scanf("%lld", &a[i]);
  pre[1] = a[1];
  suf[n] = a[n];
  // Creating and computing gcd of set d_i = {a_j | j != i}
  for (int i = 2; i <= n; i++)
    pre[i] = gcd(pre[i - 1], a[i]);
  for (int i = n - 1; i >= 1; i--)
    suf[i] = gcd(suf[i + 1], a[i]);
  for (int i = 0; i < n; i++)
    if(!i)
      ans = suf[2];
    else if(i == n - 1)
      ans = ans * pre[n - 1] / gcd(pre[n - 1], ans);
    else
      ans = ans * gcd(pre[i], suf[i + 2]) / gcd(gcd(pre[i], suf[i + 2]), ans);
  printf("%lld\n", ans);
  return 0;
}
