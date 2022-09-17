// DPKNSNA1

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 9;
typedef long long ll;
int m, n, v[506];
ll f[N];

struct Data {
	int v, w;
	bool operator < (const Data& other) const {
		return w < other.w;
	}
} a[506];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 0; i < n; ++i) cin >> a[i].v >> a[i].w;
	sort(a, a + n);

	ll sum = 0;
	for (int i = 0, v, w; i < n; ++i) {
		sum += a[i].w;
		v = a[i].v, w = a[i].w;
		for (int j = m; j >= w; --j) if (f[j] < f[j - w] + v) f[j] = f[j - w] + v;
	}
	cout << *max_element(f, f + m + 1);
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    