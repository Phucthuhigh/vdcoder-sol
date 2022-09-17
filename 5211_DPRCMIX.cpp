// DPRCMIX

#include <iostream>
#include <cmath>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 106, oo = (int)1e9 + 7;
int n, a[N], num[N][N], dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> num[i][i];
			dp[i][i] = 0;
		}

		for (int len = 2; len <= n; ++len)
			for (int l = 1, r = len; r <= n; ++l, ++r)
			{
				num[l][r] = (num[l][l] + num[l + 1][r]) % 100;
				dp[l][r] = oo;
				for (int k = l; k < r; ++k)
				{
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + num[l][k] * num[k + 1][r]);
				}
			}

		cout << dp[1][n] << '\n';
	}

	return 0;
}
    