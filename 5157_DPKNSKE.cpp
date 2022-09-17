// DPKNSKE

#include <iostream>
using namespace std;
bool max(bool x, bool y) { return (x || y); }
int main()
{
	ios_base::sync_with_stdio(false);
	long t, a[101];
	bool f[101][50001];
	cin >> t;
	for (long u = 0, n; u < t; ++u)
	{
		cin >> n;
		long  sum = 0;
		for (long i = 1; i <= n; ++i) { cin >> a[i]; sum += a[i]; }
		f[0][0] = true;
		for (long j = 1; j <= sum; ++j) f[0][j] = false;
		for (long i = 1; i <= n; ++i)
		{
			for (long j = 0; j < a[i]; ++j) f[i][j] = f[i - 1][j];
			for (long j = a[i]; j <= sum; ++j) f[i][j] = max(f[i - 1][j - a[i]], f[i - 1][j]);

		}
		long minn = sum;
		for (long j = 1; j <= sum / 2; ++j) if (f[n][j] && f[n][sum - j]) minn = sum - 2 * j;
		cout << minn << '\n';
	}
}
    