// DPLCSCOU

#include <iostream>
#include <string>
#include <algorithm>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = (int)5e3 + 7, mod = 25071987;
int dp[N][N], m, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	string s1, s2;
	cin >> s1 >> s2;
	m = s1.size(), n = s2.size();
	s1 = " " + s1, s2 = " " + s2;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + (s1[i] == s2[j] ? 1 : -dp[i - 1][j - 1]);
			if (dp[i][j] < 0) dp[i][j] += mod;
			else if (dp[i][j] > mod) dp[i][j] -= mod;
		}
	cout << dp[m][n];
	return 0;
}
    