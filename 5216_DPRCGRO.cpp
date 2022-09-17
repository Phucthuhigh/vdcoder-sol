// DPRCGRO

#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 206, mod = (int)1e9 + 7;
int n, dp[N][N * 10];
bool avail[N][N * 10];
string s;

int cal(int cnt, int num)
{
	if (cnt == n) return 1;
	if (avail[cnt][num]) return dp[cnt][num];

	avail[cnt][num] = true;
	dp[cnt][num] = 0;

	for (int i = cnt, sum = 0; i < n; ++i)
	{
		sum += s[i] - '0';
		if (sum < num) continue;
		dp[cnt][num] += cal(i + 1, sum);
		if (dp[cnt][num] > mod) dp[cnt][num] -= mod;
	}
	return dp[cnt][num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test = 1;
	while (cin >> s)
	{
		if (s == "bye") break;
		memset(avail, false, sizeof(avail));
		n = s.size();

		cout << test++ << ". " << cal(0, 0) << '\n';
	}

	return 0;
}
    