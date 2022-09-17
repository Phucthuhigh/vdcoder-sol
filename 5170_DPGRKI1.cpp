// DPGRKI1

#include <iostream>
using namespace std;
long long a[1002];
long long max(long long a, long long b, long long c)
{
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	long m, n;
	cin >> m >> n;
	for (long i = 0; i < m; ++i)
	{
		long long tmp[n + 2];
		for (long j = 0; j <= n + 1; ++j) tmp[j] = a[j];
		for (long j = 1, temp; j <= n; ++j)
		{
			cin >> temp;
			a[j] = max(tmp[j - 1], tmp[j], tmp[j + 1]) + temp;
		}
	}
	long long maxx = 0;
	for (long i = 1; i <= n; ++i) if (maxx < a[i]) maxx = a[i];
	cout << maxx;
	return 0;
}
    