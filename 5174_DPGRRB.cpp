// DPGRRB

#include <iostream>
#include <cmath>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 1006, mod = (int)1e9 + 7;
int n, m, p, dp[N][N];
bool check[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> p;
	for (long i = 0, x, y; i < p; ++i)
	{
		cin >> x >> y;
		check[x][y] = true;
	}

	dp[0][1] = 1;
	for (long i = 1; i <= m; ++i)
		for (long j = 1; j <= n; ++j)
			if (!check[i][j])
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
	
	cout << dp[m][n];
	return 0;
}
    