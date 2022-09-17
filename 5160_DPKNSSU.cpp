// DPKNSSU

#include <iostream>
using namespace std;
long f[101][10001];
int main()
{
	long n, m, k;
	cin >> n >> m >> k;
	f[0][0] = 1;
	for (long i = 1, a; i <= n; ++i)
	{
		cin >> a;
		for (long j = 0; j <= m; ++j) f[i][j] = f[i - 1][j];
		for (long j = a; j <= m; ++j) f[i][j] += f[i - 1][j - a];
	}
	if (f[n][m] >= k) cout << "ENOUGH";
	else cout << f[n][m];
}
    