// DPKNSLAN

#include <iostream>
using namespace std;
int t, w, n;
long long dp[1002];
int main()
{
	cin >> t >> w >> n;
	t /= (w << 1) + w;
	for (int i = 0, d, v; i < n; ++i)
	{
		cin >> d >> v;
		for (int j = t; j >= d; --j)
			dp[j] = max(dp[j], dp[j - d] + v);
	}
	long long maxx = dp[0];
	for (int i = 1; i <= t; ++i) maxx = max(maxx, dp[i]);
	cout << maxx;
	return 0;
}
    