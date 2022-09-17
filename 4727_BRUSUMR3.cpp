// BRUSUMR3

#include <iostream>
using namespace std;
long long a[1101][1101];
long m, n, k; // b ngang c doc
long long max(const long long& x, const long long& y) { if (x > y) return x; return y; }
int main()
{
	cin >> m >> n >> k;
	long ktmp = k, x, y, u, v, c;
	while (ktmp--)
	{
		cin >> x >> y >> u >> v >> c;
		a[x][y] += c;
		a[x][v + 1] -= c;
		a[u + 1][y] -= c;
		a[u + 1][v + 1] += c;
	}

	for (long i = 1; i <= m; ++i)
	{
		long long sum = 0;
		for (long j = 1; j <= n; ++j)
		{
			sum += a[i][j];
			a[i][j] = sum;
		}
	}

	for (long j = 1; j <= n; ++j)
	{
		long long sum = 0;
		for (long i = 1; i <= m; ++i)
		{
			sum += a[i][j];
			a[i][j] = sum;
		}
	}

	for (long i = 1; i <= m; ++i)
	{
		for (long j = 1; j <= n; ++j)
			cout << a[i][j] + 1 << ' ';
		cout << '\n';
	}

	return 0;
}
    