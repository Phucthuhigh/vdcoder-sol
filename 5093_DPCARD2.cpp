// DPCARD2

#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int N = (int)1e5 + 9;
int c, n, color[5] = { 0, 1, 2, 3, 4 }, bit[N];
struct Data {
	int x, y, id;
	bool operator < (const Data& other) const {
		return color[x] < color[other.x] || (color[x] == color[other.x] && y < other.y);
	}
} a[N];

int getmax(int p) {
	int ans = 0;
	for (; p > 0; p -= p & (-p)) ans = max(ans, bit[p]);
	return ans;
}

void update(int p, int val) {
	for (; p <= n; p += p & (-p)) bit[p] = max(bit[p], val);
}

int turns() {
	sort(a + 1, a + n + 1);
	fill(bit + 1, bit + n + 1, 0);
	int ans = 0;
	for (int i = 1, lis; i <= n; ++i) {
		lis = getmax(a[i].id - 1) + 1;
		ans = max(ans, lis);
		update(a[i].id, lis);
	}
	return ans;
}

void _next() {
	int j = c - 1, k, r, s;
	while (j > 0 && color[j] > color[j + 1]) --j;
	k = c;
	while (color[j] > color[k]) --k;
	swap(color[j], color[k]);
	r = j + 1; s = c;
	while (r < s) swap(color[r++], color[s--]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n; n *= c;
	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y, a[i].id = i;
	int res = turns(), fact = 1; for (int i = 2; i <= c; ++i) fact *= i;
	for (int i = 1; i < fact; ++i) {
		_next();
		res = max(res, turns());
	}
	cout << n - res;
	return 0;
}
    