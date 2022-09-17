// DPKNSCO2

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 506, M = N * N;
ll m, trace[N];
int n, c[N], dp[N][M];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	
	dp[0][0] = 0;
	fill(dp[0] + 1, dp[0] + M, M + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < c[i]; ++j) dp[i][j] = dp[i - 1][j];
		for (int j = c[i]; j < M; ++j) dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);
	}
	
	ll cost = m + 1;
	int ii = 0;
	for (int i = 1; i < M; ++i)
		if (cost > (m / i) * dp[n][i] + dp[n][m % i]) {
			cost = (m / i) * dp[n][i] + dp[n][m % i];
			ii = i;
		}

	if (cost == m + 1) cout << -1;
	else {
		cout << cost << '\n'; // dp[ii] * (m / i) + dp[m % ii]

		int i = n, j = ii;
		while (j > 0) {
			if (dp[i][j] == dp[i - 1][j]) --i;
			else {
				++trace[i];
				j -= c[i];
			}
		}
		for (int i = 1; i <= n; ++i) trace[i] *= (m / ii);

		i = n, j = m % ii;
		while (j > 0) {
			if (dp[i][j] == dp[i - 1][j]) --i;
			else {
				++trace[i];
				j -= c[i];
			}
		}

		for (int i = 1; i <= n; ++i) cout << trace[i] << ' ';
	}
	return 0;
}
    