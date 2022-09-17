// DPRCEDT

#include <iostream>
#include <string>

using namespace std;
string a, b;
int m, n, dp[2006][2006];

void process() {
	m = a.size(), n = b.size();
	a = " " + a, b = " " + b;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
	cout << dp[m][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 1; i <= 2000; ++i) dp[0][i] = dp[i][0] = i;
	int t; cin >> t; while (t-- > 0) {
		cin >> a >> b;
		process();
	}
}
    