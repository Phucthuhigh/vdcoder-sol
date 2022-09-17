// DPKNSCO

#include <iostream>
using namespace std;
long f[201][1001], n, m;
long min(long x, long y) { if (x < y) return x; return y; }
int main()
{
	long t;
	cin >> t;
	for (long u = 0; u < t; ++u)
	{
		cin >> m >> n;
		f[0][0] = 0;
		for (long i = 1; i <= m; ++i) f[0][i] = 1001;
		for (long i = 1, c; i <= n; ++i)
		{
			cin >> c;
			for (long j = 0; j < c && j <= m; ++j) f[i][j] = f[i - 1][j];
			f[i][c] = 1;
			for (long j = c + 1; j <= m; ++j)
			{
				if (f[i][j - c] > 0) f[i][j] = min(f[i - 1][j], f[i][j - c] + 1);
				else f[i][j] = f[i - 1][j];
			}
		}
		if (f[n][m] == 1001) cout << -1 << '\n';
		else cout << f[n][m] << '\n';
	}
	return 0;
}
    