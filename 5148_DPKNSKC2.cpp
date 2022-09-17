// DPKNSKC2

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, m, a[1001], b[1001];
long long dp[1001][11115];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		dp[i][0] = 0;
		for (int j = 1; j < b[i]; ++j) dp[i][j] = dp[i - 1][j];
		for (int j = b[i]; j <= m; ++j)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - b[i]] + a[i]);
	}

	cout << dp[n][m] << '\n';

	stack<int> res;
	for (int i = n, j = m, x; i > 0; --i)
	{
		x = 0;
		while (j >= b[i] && dp[i][j] == dp[i][j - b[i]] + a[i])
		{
			++x;
			j -= b[i];
		}
		res.push(x);
	}

	while (!res.empty())
	{
		cout << res.top() << ' ';
		res.pop();
	}

	return 0;
}
    