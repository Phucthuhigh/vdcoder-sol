// BTKCATU4

#include <iostream>
#include <utility>
#include <algorithm>
#define ff first
#define ss second
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1 << 21;
int n, w[42], v[42], na, nb;
ll U, V, seg[N << 2], aw[N], av[N], bw[N], bv[N];
pll a[N];

void Try1(int i, ll ww, ll val) {
    if (ww > V) return;
    if (i > n / 2) {
        a[++na] = mp(ww, val);
        return;
    }
    Try1(i + 1, ww, val);
    Try1(i + 1, ww + w[i], val + v[i]);
}

void Try2(int i, ll ww, ll val) {
    if (ww > V) return;
    if (i > n) {
        bw[++nb] = ww;
        bv[nb] = val;
        return;
    }
    Try2(i + 1, ww, val);
    Try2(i + 1, ww + w[i], val + v[i]);
}

void build(int node, int l, int r) {
    if (l == r) seg[node] = av[l];
    else {
        int mid = (l + r) >> 1, n1 = node << 1, n2 = n1 | 1;
        build(n1, l, mid);
        build(n2, mid + 1, r);
        seg[node] = max(seg[n1], seg[n2]);
    }
}

ll getmax(int node, int l, int r, int a, int b) {
    if (a <= l && r <= b) return seg[node];
    if (b < l || r < a) return 0;
    int mid = (l + r) >> 1, n1 = node << 1, n2 = n1 | 1;
    return max(getmax(n1, l, mid, a, b), getmax(n2, mid + 1, r, a, b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> U >> V; for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    Try1(1, 0, 0);
    Try2(n / 2 + 1, 0, 0);

    sort(a, a + na + 1);
    for (int i = 1; i <= na; ++i) aw[i] = a[i].ff, av[i] = a[i].ss;
    build(1, 1, na);

    ll ans = 0;
    for (int i = 1, lo, hi; i <= nb; ++i) {
        lo = lower_bound(aw + 1, aw + na + 1, U - bw[i]) - aw;
        hi = upper_bound(aw + 1, aw + na + 1, V - bw[i]) - aw - 1;
        ans = max(ans, getmax(1, 1, na, lo, hi) + bv[i]);
    }
    cout << ans;
    return 0;
}
    