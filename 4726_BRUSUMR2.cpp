// BRUSUMR2

#include <iostream>
using namespace std;
long long a[700][700], b[700][700], c[700][700], m, n, k; // b ngang c doc
long long max(const long long& x, const long long& y) { if (x > y) return x; return y; }
int main()
{
	cin >> m >> n >> k;
	for (long i = 0; i < m; ++i)
		for (long j = 0; j < n; ++j) cin >> a[i][j];

	if (k == 1)
	{
		long long res = -1000000000000000;
		for (long i = 0; i < m; ++i)
		{
			for (long j = 0; j < n; ++j)
			{
				res = max(res, a[i][j]);
			}
		}

		cout << res;
		return 0;
	}

	for (long i = 0; i < m; ++i)
	{
		long long sum = 0;
		for (long j = 0; j < k; ++j) sum += a[i][j];
		b[i][0] = sum;

		for (long j = k; j < n; ++j)
		{
			sum = sum + a[i][j] - a[i][j - k];
			b[i][j - k + 1] = sum;
		}
	}

	for (long j = 0; j < n; ++j)
	{
		long long sum = 0;
		for (long i = 0; i < k; ++i) sum += a[i][j];
		c[0][j] = sum;

		for (long i = k; i < m; ++i)
		{
			sum = sum + a[i][j] - a[i - k][j];
			c[i - k + 1][j] = sum;
		}
	}
	n = n - k + 1;
	m = m - k + 1;

	long long res = -1000000000000000;
	for (long i = 0; i < m; ++i)
	{
		for (long j = 0; j < n; ++j)
		{
			res = max(res, b[i][j] + b[i + k - 1][j] + c[i][j] + c[i][j + k - 1] - a[i][j] - a[i][j + k - 1] - a[i + k - 1][j] - a[i + k - 1][j + k - 1]);
		}
	}

	cout << res;
	return 0;
}
    