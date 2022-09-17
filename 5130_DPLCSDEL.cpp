// DPLCSDEL

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
int dp[3033][3033];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	for (int i = 0; i < s.size(); ++i) dp[i][0] = i;
	for (int j = 0; j < t.size(); ++j) dp[0][j] = j;

	for (int i = 1; i < s.size(); ++i)
		for (int j = 1; j < t.size(); ++j)
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;

	cout << dp[s.size() - 1][t.size() - 1];
	
	return 0;
}
    