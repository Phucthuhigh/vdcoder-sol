// DPDSTT

#include <iostream>
using namespace std;
long gcd(long a, long b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}
long long a[1000], f[1000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i];
		f[i] = 1;
	}
	for (long i = 1; i < n; ++i)
		for (long j = 0; j < i; ++j)
			if (gcd(a[i], a[j]) == 1 && f[i] < f[j] + 1) f[i] = f[j] + 1;
	long maxx = 0;
	for (long i = 1; i < n; ++i) if (maxx < f[i]) maxx = f[i];
	cout << maxx;
	return 0;
}
    