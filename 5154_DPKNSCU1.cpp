// DPKNSCU1

#include <iostream>

using namespace std;

const int N = 2050;
int n, k, a[N], dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test; cin >> test;
	while (test-- > 0)
	{
		cin >> n >> k;
		n += 10;
		for (int i = 11; i <= n; ++i) cin >> a[i];

		int res = 0;
		for (int i = 11; i <= n; ++i)
		{
			for (int j = 1; j < a[i]; ++j) dp[i][j] = 0;
			for (int j = a[i]; j <= k; ++j)
			{
				dp[i][j] = 0;
				for (int d = 2; d <= 3; ++d)
				{
					dp[i][j] = max(max(dp[i - d][j], dp[i - d][j - a[i]] + a[i]), dp[i][j]);
					res = max(res, dp[i][j]);
				}
			}
		}
		cout << res << ' ';
	}
	return 0;
}
    