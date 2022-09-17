// DPLCSAX

#include <iostream>
using namespace std;

typedef long long ll;
const int N = 2020;
int m, n, tmp, a[N], b[N], dp[N][N];

int lcs() {
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i][j] = (a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]));
	return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int d; cin >> d;
	while (d--) {
		m = 0; cin >> tmp;
		while (tmp != 0) {
			a[++m] = tmp;
			cin >> tmp;
		}

		int res = 0;
		cin >> tmp;
		while (tmp != 0) {
			n = 0;
			while (tmp != 0) {
				b[++n] = tmp;
				cin >> tmp;
			}

			res = max(res, lcs());
			cin >> tmp;
		}
		cout << res << '\n';
	}
	return 0;
}
    