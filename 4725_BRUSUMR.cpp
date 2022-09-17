// BRUSUMR

#include <iostream>
using namespace std;
long long a[700][700], b[700][700], m, n, k;
long long max(const long long& x, const long long& y) { if (x > y) return x; return y; }
int main()
{
	cin >> m >> n >> k;
	for (long i = 0; i < m; ++i)
		for (long j = 0; j < n; ++j) cin >> a[i][j];
		
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
	n = n - k + 1;
	
	for (long j = 0; j < n; ++j)
	{
		long long sum = 0;
		for (long i = 0; i < k; ++i) sum += b[i][j];
		a[0][j] = sum;
		
		for (long i = k; i < m; ++i)
		{
			sum = sum + b[i][j] - b[i - k][j];
			a[i - k + 1][j] = sum;
		}
	}
	m = m - k + 1;
	
	long long res = 0;
	for (long i = 0; i < m; ++i)
		for (long j = 0; j < n; ++j) res = max(res, a[i][ j]);
		
	cout << res;
	return 0;
}
    