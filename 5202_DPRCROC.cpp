// DPRCROC

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define mp make_pair

using namespace std;
typedef long long ll;

const int N = 206, mod = (int)1e9 + 7;
int n, dp[N][N], ngot[N], chua[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test = 1;
	cin >> test;
	while (test-- > 0)
	{
		cin >> n;
		char c;
		for (int i = 1; i <= n; ++i)
		{
			cin >> c;
			ngot[i] = ngot[i - 1];
			chua[i] = chua[i - 1];
			if (c == '1') ++ngot[i];
			else ++chua[i];
		}

		for (int len = 1; len <= n; ++len)
			for (int l = 1, r = len; r <= n; ++l, ++r)
			{
				dp[l][r] = (ngot[r] - ngot[l - 1] > chua[r] - chua[l - 1] ? r - l + 1 : 0);
				for (int k = l; k < r; ++k)
					dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}

		cout << dp[1][n] << '\n';
	}

	return 0;
}
    