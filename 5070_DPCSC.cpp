// DPCSC

#include <iostream>
#include <algorithm>

using namespace std;

int n, a[2001], dp[51][2001];

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
//	sort(a, a + n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	input();
	for (int i = 0; i < n; ++i)
	{
		for (int d = 1; d <= 50; ++d) dp[d][i] = 1;
		for (int j = i - 1, d; j >= 0; --j)
		{
			d = a[i] - a[j];
			if (d >= 1 && d <= 50)
			{
				dp[d][i] = max(dp[d][i], dp[d][j] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int d = 1; d <= 50; ++d)
			res = max(res, dp[d][i]);

	cout << res;

	return 0;
}
    