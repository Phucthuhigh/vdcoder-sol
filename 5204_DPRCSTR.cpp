// DPRCSTR

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 3004, mod = (int)1e9 + 7;
int n, k, t;
ll a[N], mini[N][N], S[N][N], dp[N][N];

void buildS()
{
	for (int len = 2; len <= n; ++len)
	{
		for (int l = 1, r = len; r <= n; ++l, ++r)
		{
			mini[l][r] = min(a[l], mini[l + 1][r]);
			S[l][r] = max(mini[l][r] * (r - l + 1), max(S[l][r - 1], S[l + 1][r]));
		}
	}
}

void buildDP()
{
	for (int i = 1; i <= k; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			dp[i][j] = dp[i][j - 1]; // not get
			for (int ii = j; ii >= max(i, j - t + 1); --ii)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][ii - 1] + S[ii][j]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> t;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		mini[i][i] = S[i][i] = a[i];
	}
	buildS();
	buildDP();

	ll res = 0;
	for (int i = k; i <= n; ++i) res = max(res, dp[k][i]);
	cout << res;

	return 0;
}
    