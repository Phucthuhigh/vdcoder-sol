// DPRCXDS

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 502, mod = (int)1e9 + 7;
int n1, n2, n3, dp[66][66][66];
string s1, s2, s3;
bool avail[66][66][66];

int getAns(int i, int j, int k)
{
	if (k == 0) return 1;
	if (avail[i][j][k]) return dp[i][j][k];
	dp[i][j][k] = 0; avail[i][j][k] = true;
	for (int ite = 1; ite <= i; ++ite)
		if (s1[ite] == s3[k]) (dp[i][j][k] += getAns(ite - 1, j, k - 1)) %= mod;
	for (int ite = 1; ite <= j; ++ite)
		if (s2[ite] == s3[k]) (dp[i][j][k] += getAns(i, ite - 1, k - 1)) %= mod;
	return dp[i][j][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0)
	{
		memset(avail, false, sizeof(avail));
		cin >> s1 >> s2 >> s3;
		n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		s1 = " " + s1, s2 = " " + s2, s3 = " " + s3;

		cout << getAns(n1, n2, n3) << '\n';
	}

	return 0;
}
    