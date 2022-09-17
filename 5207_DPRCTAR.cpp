// DPRCTAR

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 3004, mod = (int)1e9 + 7;
int n, k;
ll a[N], dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		dp[i][i] = a[i];
	}

	for (int len = 2; len <= n; ++len)
		for (int l = 1, r = len; r <= n; ++l, ++r)
			dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
	cout << dp[1][n];

	return 0;
}
    