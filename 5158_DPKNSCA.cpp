// DPKNSCA

#include <iostream>
using namespace std;
bool f[101][20001];
long min(long x, long y) { if (x < y) return x; return y; }
int main()
{
	long t;
	cin >> t;
	for (long u = 0, n; u < t; ++u)
	{
		cin >> n;
		long sum = 0;
		f[0][0] = true;
		for (long j = 1; j <= 20000; ++j) f[0][j] = false;
		for (long i = 1, a; i <= n; ++i)
		{
			cin >> a;
			sum += a;
			for (long j = 0; j < a && j < 20001; ++j) f[i][j] = f[i - 1][j];
			for (long j = a; j < 20001; ++j) if (f[i - 1][j - a]) f[i][j] = true;
			else f[i][j] = f[i - 1][j];
		}
		for (long j = 0; j <= sum; ++j) if (f[n][j]) cout << j << ' ';
		cout << '\n';
	}
	return 0;
}
    