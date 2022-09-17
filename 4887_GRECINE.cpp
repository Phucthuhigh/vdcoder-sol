// GRECINE

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = (int)2e5 + 8;
int n, k, s, t, c[N], v[N], g[N];

bool check(int x) {
	int tme = 0;
	for (int i = 1, ss, a, b; i <= k; ++i) {
		if (g[i] - g[i - 1] > x) return false;
		ss = (g[i] - g[i - 1]); // a + 2b = x, a + b = tmp (a 2p, b 1p)
		b = min(ss, x - ss), a = ss - b;
		tme += b + 2 * a;
	}
	return (tme <= t);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k >> s >> t;
	for (int i = 1; i <= n; ++i) cin >> c[i] >> v[i];
	for (int i = 1; i <= k; ++i) cin >> g[i]; g[++k] = s;
	sort(g + 1, g + k);

	int mid, l = 0, r = (int)1e9;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	int vmi = r + 1;
	int cost = 2e9;
	for (int i = 1; i <= n; ++i)
		if (vmi <= v[i]) cost = min(cost, c[i]);
	cout << (cost == 2e9 ? -1 : cost);

	return 0;
}
    