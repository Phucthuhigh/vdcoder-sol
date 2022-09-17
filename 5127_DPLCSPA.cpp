// DPLCSPA

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, dp[5003][5003];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> s;
	s = ' ' + s;
	for (int i = 0; i < s.size(); ++i) dp[i][i] = 0;
	for (int len = 1; len < s.size(); ++len)
	{
		for (int l = 1, r = l + len; r < s.size(); ++l, ++r)
			if (s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1];
			else dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
	}

	cout << dp[1][s.size() - 1];

	return 0;
}
    