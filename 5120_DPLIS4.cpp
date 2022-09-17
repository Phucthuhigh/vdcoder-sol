// DPLIS4

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5 + 9, inf = 1e9 + 7;
int n, a[N], b[N], ma, mb;

inline void read(int& x) {
	register char c = getchar();
	while ('0' > c || c > '9') c = getchar();
	x = c - 48;
	for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - 48;
}

int tmp[N];
void compress() {
	copy(a, a + n, tmp);
	sort(tmp, tmp + n);
	ma = unique(tmp, tmp + n) - tmp;
	for (int i = 0; i < n; ++i) a[i] = upper_bound(tmp, tmp + ma, a[i]) - tmp;

	copy(b, b + n, tmp);
	sort(tmp, tmp + n);
	mb = unique(tmp, tmp + n) - tmp;
	for (int i = 0; i < n; ++i) b[i] = upper_bound(tmp, tmp + mb, b[i]) - tmp;
}

vector<int> node[N], bit[N];
void init() {
	for (int i = 0; i < n; ++i) {
		for (int p = a[i]; p <= ma; p += p & (-p)) node[p].emplace_back(b[i]); // in future, if upd a[i], we will join b[i] in node[p]
		for (int p = a[i]; p > 0; p -= p & (-p)) node[p].emplace_back(b[i]); // in future, if qry a[i], we will join b[i] in node[p]
	}

	for (int i = 1; i <= ma; ++i) {
		node[i].emplace_back(-1);
		node[i].emplace_back(inf);
		sort(node[i].begin(), node[i].end());
		node[i].resize(unique(node[i].begin(), node[i].end()) - node[i].begin()); // compress
		bit[i].assign(node[i].size() + 1, 0); // corresponding to each node[i]
	}
}

int qry(int i, int j) {
	int ans = 0;
	for (int p; i > 0; i -= i & (-i)) {
		p = upper_bound(node[i].begin(), node[i].end(), j) - node[i].begin() - 1; // last node <= j
		for (; p > 0; p -= p & (-p)) ans = max(ans, bit[i][p]); // get from 1 to p
	}
	return ans;
}

void upd(int i, int j, int val) {
	for (int p; i <= ma; i += i & (-i)) {
		p = lower_bound(node[i].begin(), node[i].end(), j) - node[i].begin(); // first node >= j (I mean == j because node[i].count(j) == true)
		for (; p <= node[i].size(); p += p & (-p)) bit[i][p] = max(bit[i][p], val); // update from p to inf
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	read(n);
	for (int i = 0; i < n; ++i) read(a[i]), read(b[i]);
	compress();
	init();

	int ans = 0;
	for (int i = 0, tmp; i < n; ++i) {
		tmp = qry(a[i] - 1, b[i] - 1) + 1;
		ans = max(ans, tmp);
		upd(a[i], b[i], tmp);
	}
	cout << ans;
}
    