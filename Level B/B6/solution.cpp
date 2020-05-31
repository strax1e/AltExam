// https://codeforces.com/contest/710/problem/D

#include <iostream>
#include <math.h>

long a1, b1, a2, b2, l, r;

long _ceil( long, long );
long _floor( long a, long b ) 
{ 
	return b < 0 ? _floor(-a, -b) : a < 0 ? -_ceil(-a, b) : a / b; 
}
long _ceil( long a, long b ) 
{ 
	return b < 0 ? _ceil(-a, -b) : a < 0 ? -_floor(-a, b) : (a + b - 1) / b; 
}

// extended Euclidean algorithm
long gcdext( long a, long b, long &x, long &y ) 
{
	if (!a) 
	{
		x = 0, y = 1;
		return b;
	}
	long xx, yy, g = gcdext(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}

void main(void)
{
	std::cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
	
	l = fmax(0ll, _ceil(l - b1, a1));
	r = _floor(r - b1, a1);
	if (l > r) 
	{
		puts("0");
		return;
	}

	long A = a1, B = -a2, C = b2 - b1;
	long x0, y0;
	long g = gcdext(A, B, x0, y0);

	if (C % g) 
	{
		puts("0");
		return;
	}

	if (g < 0) 
	{
		g = -g;
		x0 = -x0;
		y0 = -y0;
	}

	long L = _ceil(r * g - x0 * C, B);
	long R = _floor(l * g - x0 * C, B);
	R = fmin(R, _floor(y0 * C, A));

	long ans = fmax(0ll, R - L + 1);
	std::cout << ans << std::endl;
}