// DPMI2

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("tune=native")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#define r first
#define l second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1e5 + 6, mod = (int)1e8;
int n, dp[N];
pii a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while (n != -1) {
		for (int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
		sort(a + 1, a + n + 1);

		fill(dp, dp + n + 1, 0);
		for (int i = 1, j; i <= n; ++i) {
			dp[i] = dp[i - 1];
			j = upper_bound(a, a + i, a[i].l, [](const int& x, const pii& y) {
				return (x < y.r);
			}) - a - 1;
			dp[i] = dp[i - 1] + 1 + dp[j];
			if (dp[i] >= mod) dp[i] -= mod;
		}

		int tmp = dp[n], len = (tmp == 0 ? 1 : 0);
		while (tmp > 0) ++len, tmp /= 10;
		for (int i = len; i < 8; ++i) cout << 0;
		cout << dp[n] << '\n';
		cin >> n;
	}
}
    