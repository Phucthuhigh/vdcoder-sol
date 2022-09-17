// DPBEACH

#include <iostream>
#include <algorithm>

using namespace std;

int n, a[5000], dp[2][5000];

void set_dp_inc()
{
	for (int i = n - 1; i >= 0; --i)
	{
		dp[0][i] = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] < a[j])
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
		}
	}
}

void set_dp_dec()
{
	for (int i = n - 1; i >= 0; --i)
	{
		dp[1][i] = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j])
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> a[i];
	set_dp_inc();
	set_dp_dec();

	int res = 1;
	for (int i = 0; i < n; ++i)
		res = max(res, dp[0][i] + dp[1][i] - 1);

	cout << res;

	return 0;
}
    