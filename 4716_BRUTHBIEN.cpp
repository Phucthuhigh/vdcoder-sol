// BRUTHBIEN

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, a[5555], c[5555];
long long dp[5555];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> c[i];

	for (int j = 0; j < n; ++j)
	{
		dp[j] = 5000000000;
		for (int k = j + 1; k < n; ++k)
		{
			if (a[j] < a[k] && dp[j] > c[k]) dp[j] = c[k];
		}
	}

	long long res = 5000000000;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] < a[j] && (long long)c[i] + c[j] + dp[j] < res)
				res = (long long)c[i] + c[j] + dp[j];
		}

	cout << (res == 5000000000 ? -1 : res);
	
	return 0;
}
    