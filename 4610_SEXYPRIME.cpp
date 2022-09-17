// SEXYPRIME

#include <iostream>
using namespace std;
long long a[10000];
bool check[1000000];
void sieve()
{
	for (long i = 2; i * i < 1000000; ++i)
		if (!check[i]) for (long j = i * i; j < 1000000; j += i) check[j] = true;
	long cnt = 0;
	for (long i = 11; i < 1000000; ++i)
		if (!check[i] && !check[i - 6]) if (cnt < 10000) a[cnt++] = i - 6; else break;
}
int main()
{
	long t, n;
	cin >> t;
	sieve();
	while (t--)
	{
		cin >> n;
		cout << a[n - 1] << ' ' << a[n - 1] + 6 << '\n';
	}
	return 0;
}
    