// DPRCCOW

#pragma GCC optimization ("O3")
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 5006, oo = (int)1e9 + 7;
int n, m, b[N], c[N], dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	sort(b + 1, b + m + 1);
	sort(c + 1, c + n + 1);

	for (int i = 1; i <= m; ++i)
	{
		dp[i][i] = dp[i - 1][i - 1] + abs(b[i] - c[i]);
		for (int j = i + 1; j <= n; ++j)
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(b[i] - c[j]));
	}
	cout << dp[m][n];
	return 0;
}
    