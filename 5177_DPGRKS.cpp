// DPGRKS

#include <iostream>
#include <cmath>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 506, oo = (int)1e9 + 7;
int n, m, y[N][N], b[N][N], dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	while (m != 0)
	{
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) cin >> y[i][j];

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) cin >> b[i][j];

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
			{
				y[i][j] += y[i][j - 1];
				b[i][j] += b[i - 1][j];
				dp[i][j] = max(dp[i - 1][j] + y[i][j], dp[i][j - 1] + b[i][j]);
			}

		cout << dp[m][n] << '\n';
		cin >> m >> n;
	}

	return 0;
}
    