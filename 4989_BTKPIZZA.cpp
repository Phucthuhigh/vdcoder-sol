// BTKPIZZA

#pragma GCC optimization ("O3")
#pragma GCC target("tune=native")

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int M = 22, N = 106;
int k, r, m, X[M], Y[M], n, x[N], y[N], s[N], ans, was[N];

#define sqr(x) (x) * (x)
bool check(int i, int j) {
	return (sqr(X[i] - x[j]) + sqr(Y[i] - y[j]) <= r * r);
}

int sum;
void Try(int i, int cnt) {
	ans = max(ans, sum);
	if (i <= m && cnt < k) {
		for (; i <= m - k + cnt + 1; ++i) {
			for (int j = 1; j <= n; ++j)
				if (!was[j] && check(i, j)) was[j] = i, sum += s[j];
			Try(i + 1, cnt + 1);
			for (int j = 1; j <= n; ++j) if (was[j] == i) was[j] = 0, sum -= s[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> k >> r >> m;
	for (int i = 1; i <= m; ++i) cin >> X[i] >> Y[i];
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> s[i];

	Try(1, 0);
	cout << ans;
	return 0;
}
    