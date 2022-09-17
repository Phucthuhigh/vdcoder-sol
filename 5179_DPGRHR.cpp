// DPGRHR

#include <iostream>
#include <deque>

using namespace std;
typedef long long ll;

const int N = 502, oo = (int)1e9;
int m, n, a[N][N], dp[N][N];

bool check(int x)
{
	dp[0][1] = x;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			if (dp[i][j] <= 0) dp[i][j] = -oo;
		}
	return (dp[m][n] > 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < N; ++i) dp[0][i] = dp[i][0] = -oo;

	int t;
	cin >> t;
	while (t-- > 0)
	{
		cin >> m >> n;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) cin >> a[i][j];

		int mid, l = 0, r = (int)1e6;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (check(mid))
				r = mid - 1;
			else l = mid + 1;
		}
		cout << r + 1 << '\n';
	}

	return 0;
}
    