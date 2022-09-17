// DPCARD

#include <iostream>
#include <algorithm>
#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;

const int N = (int)1e5 + 9;
int n, c, x[N], y[N], arr[N], bit[N];
pii a[N];

int getmax(int p) {
	int ans = 0;
	for (; p > 0; p -= p & (-p)) ans = max(ans, bit[p]);
	return ans;
}

void update(int p, int val) {
	for (; p <= n; p += p & (-p)) bit[p] = max(bit[p], val);
}

int turns() {
	sort(a + 1, a + n + 1); //3214
	fill(bit + 1, bit + n + 1, 0);
	int ans = 0;
	for (int i = 1, lis; i <= n; ++i) {
		lis = getmax(a[i].ss - 1) + 1;
		ans = max(ans, lis);
		update(a[i].ss, lis);
	}
	return n - ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n; n *= c; for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	arr[1] = 1, arr[2] = 2, arr[3] = 3, arr[4] = 4;
	int res = (int)1e9;
	do {
		for (int i = 1; i <= n; ++i) a[i] = mp(arr[x[i]] * N + y[i], i);
		res = min(res, turns());
	} while (next_permutation(arr + 1, arr + c + 1));
	cout << res;
	return 0;
}
    