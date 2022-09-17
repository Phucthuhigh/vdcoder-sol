// DPKNSHE

#include <iostream>
#include <string>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = 502, M = (int)1e4 + 7, oo = (int)1e9 + 7;
int dp[M], m, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int t, e, f;
	cin >> t;
	while (t-- > 0)
	{
		cin >> e >> f >> n;
		m = f - e;
		fill(dp + 1, dp + m + 1, oo);
		for (int i = 1, p, w; i <= n; ++i)
		{
			cin >> p >> w;
			for (int j = w; j <= m; ++j)
				dp[j] = min(dp[j], dp[j - w] + p);
		}

		cout << (dp[m] == oo ? -1 : dp[m]) << '\n';
	}

	return 0;
}
    