// BRUTICHSO

#include <iostream>
using namespace std;
long tichso(long k)
{
	long res = 1;
	while (k > 0)
	{
		res *= k % 10;
		k /= 10;
	}
	return res;
}
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	long n;
	cin >> n;

	long tich1 = tichso(n), i = 10, j = 9, t = n - (n % 10) - 1;
	tich1 = max(tich1, tichso(t));
	while (t > j)
	{
		t = (n / i - 1) * i + j;
		tich1 = max(tich1, tichso(t));
		i *= 10;
		j = j * 10 + 9;
	}

	cout << tich1;
	return 0;
}
    