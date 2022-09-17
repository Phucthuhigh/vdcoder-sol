// GCDALTN

#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main()
{
	long long a, b, n, square, tmp_n = 1, kq = 1;
	cin >> a >> b >> n;
	a = gcd(a, b);
	if (a == 1) { cout << 1; return 0; }
	square = a;
	while (b % square == 0 && tmp_n <= n / 2) { square *= square; tmp_n *= 2; }
	while ((b % a == 0 || b % square == 0) && tmp_n > 0)
	{
		if (b % square == 0)
		{
			kq *= square;
			b /= square;
			n -= tmp_n;
		}
		tmp_n /= 2;
		square = sqrt(square);
	}
	if (n > 0)
	{
		if (a % 2 == 0 && b % 2 == 0) kq *= 2;
		for (long long i = 3; i <= sqrt(a); i += 2)
		{
			if (a % i == 0 && b % i == 0)
			{
				kq *= i;
				if (b % (a / i) == 0) kq = kq * (n / i);
			}
		}
	}
	cout << kq;
}
    