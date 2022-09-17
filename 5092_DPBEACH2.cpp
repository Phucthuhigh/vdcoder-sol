// DPBEACH2

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], dp[2][N];

void set_dp_inc()
{
	int b[N], cnt = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int maxdp = lower_bound(b + 1, b + cnt + 1, a[i]) - b - 1;
		dp[0][i] = maxdp + 1;

		b[maxdp + 1] = a[i];
		if (maxdp == cnt) ++cnt;
	}
}

void set_dp_dec()
{
	int b[N], cnt = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int maxdp = lower_bound(b + 1, b + cnt + 1, a[i], greater<int>()) - b - 1;
		dp[1][i] = maxdp + 1;

		b[maxdp + 1] = a[i];
		if (maxdp == cnt) ++cnt;
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
    