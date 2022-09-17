// DPTOYS

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100011;
int n, v[N];
long long prf[N], dp[N];

long long sum(int l, int r)
{
	return prf[r] - prf[l - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			prf[i] = prf[i - 1] + v[i];
		}
		for (int i = n + 1; i < N; ++i) prf[i] = prf[i - 1]; // reset

		for (int i = 2; i <= n + 6; i += 2)
		{
			dp[i] = 0;
			if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + sum(i - 1, i - 1)); // x = 1
			if (i >= 4) dp[i] = max(dp[i], dp[i - 4] + sum(i - 3, i - 2)); // x = 2
			if (i >= 6) dp[i] = max(dp[i], dp[i - 6] + sum(i - 5, i - 3)); // x = 3
		}
		long long res = 0;
		for (int i = n + 1; i <= n + 6; ++i) res = max(res, dp[i]);
		cout << res << '\n';
	}

	return 0;
}
    