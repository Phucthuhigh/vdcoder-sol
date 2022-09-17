// DPCOUTLIQ

#include <iostream>
#include <string>

using namespace std;

const int N = 5050;
int n, a[N], dp[N];
long long f[N], mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int maxx = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		
		dp[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}

		f[i] = (dp[i] == 1 ? 1 : 0);
		for (int j = 1; j < i; ++j)
		{
			if (a[j] < a[i] && dp[j] + 1 == dp[i]) (f[i] += f[j]) %= mod;
		}
		
		maxx = max(maxx, dp[i]);
	}

	long long res = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i] == maxx) (res += f[i]) %= mod;
	cout << res;

	return 0;
}
    