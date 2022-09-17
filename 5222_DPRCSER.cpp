// DPRCSER

#include <iostream>

using namespace std;
typedef long long ll;

const int L = 206, N = 506;
int l, n, c[L][L], p[N], dp[L][L][N];

#define min3(a, b, c) min(a, min(b, c))
int get_res(int v1, int v2, int pos) {
	if (pos > n) return 0;
	int v3 = p[pos - 1];
	if (dp[v1][v2][pos] != -1) return dp[v1][v2][pos];
	if (v3 == p[pos]) return dp[v1][v2][pos] = get_res(v1, v2, pos + 1);
	if (v2 == p[pos]) return dp[v1][v2][pos] = get_res(v1, v3, pos + 1);
	if (v1 == p[pos]) return dp[v1][v2][pos] = get_res(v2, v3, pos + 1);
	return dp[v1][v2][pos] = min3(
		get_res(v2, v3, pos + 1) + c[v1][p[pos]],
		get_res(v1, v3, pos + 1) + c[v2][p[pos]],
		get_res(v1, v2, pos + 1) + c[v3][p[pos]]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t-- > 0) {
		cin >> l >> n;
		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= l; ++j) cin >> c[i][j];
		for (int i = 1; i <= n; ++i) cin >> p[i];
		p[0] = 3;
		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= l; ++j)
				for (int k = 1; k <= n; ++k) dp[i][j][k] = -1;
		cout << get_res(1, 2, 1) << '\n';
	}
}
    