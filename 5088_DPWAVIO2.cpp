// DPWAVIO2

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 6, inf = 1e9 + 7;
int n, a[N], t[N], g[N];

int b[N], cnt;
int binsearch(ll p) {
	int l = 1, r = cnt - 1, mid, res = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (b[mid] == p) return mid - 1;
		if (b[mid] < p) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
void set_t() {
	b[0] = -inf; cnt = 1;
	for (int i = 1, p; i <= n; ++i) {
		p = lower_bound(b + 1, b + cnt, a[i]) - b;
		if (p == cnt) b[cnt++] = a[i];
		else if (a[i] < b[p]) b[p] = a[i];
		t[i] = p;
	}
}

void set_g() {
	b[0] = -inf; cnt = 1;
	for (int i = n, p; i > 0; --i) {
		p = lower_bound(b + 1, b + cnt, a[i]) - b;
		if (p == cnt) b[cnt++] = a[i];
		else if (a[i] < b[p]) b[p] = a[i];
		g[i] = p;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	set_t();
	set_g();
	int ans = 1;
	for (int i = 2; i < n; ++i) if (t[i] != 0 && g[i] != 0) ans = max(ans, t[i] + g[i] - 1);
	cout << ans;
}
    