// DPSMAX2

#include <iostream>
#include <algorithm>
#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)1e5 + 6;
int n;
pii a[N];
ll bit[N];

ll getmax(int pos) {
	ll ans = 0;
	for (; pos; pos -= pos & (-pos))
	ans = max(ans, bit[pos]);
	return ans;
}

void update(int pos, ll val) {
	for (; pos <= n; pos += pos & (-pos)) bit[pos] = max(bit[pos], val);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i].ff, a[i].ss = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		update(a[i].ss, getmax(a[i].ss) + a[i].ff); // pos, val
	cout << getmax(n);
	return 0;
}
    