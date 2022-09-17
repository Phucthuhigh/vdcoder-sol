// DPGRNAM

#include <iostream>

using namespace std;

int m, n, a[502][502], dp[4][502][502], base = 10000000;

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) cin >> a[i][j];

	dp[0][1][1] = dp[1][1][1] = dp[2][1][1] = dp[3][1][1] = 1;

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (a[i][j] > 0)
			{
				dp[0][i][j] = (dp[0][i][j - 1] + dp[0][i - 1][j]) % base;
				dp[a[i][j]][i][j] = (dp[a[i][j]][i][j - 1] + dp[a[i][j]][i - 1][j]) % base;
			}
		}

	cout << ((dp[0][m][n - 1] + dp[0][m - 1][n]
		- (dp[1][m][n - 1] + dp[1][m - 1][n])
		- (dp[2][m][n - 1] + dp[2][m - 1][n])
		- (dp[3][m][n - 1] + dp[3][m - 1][n])) % base + base) % base;

	return 0;
}
    