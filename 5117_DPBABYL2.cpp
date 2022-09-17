// DPBABYL2

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 16006;
int n, c[N * 6], tmp[3];
pii b[N * 6];
ll dp[N * 6], bit[N * 6];
struct block {
    int d, r, h;
    bool operator < (const block& other) const {
        return (d < other.d || (d == other.d && r > other.r));
    }
} a[N * 6];

block mblock(int a, int b, int c) {
    block k; k.d = min(a, b), k.r = max(b, a), k.h = c;
    return k;
}

void compressA() {
    int cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[cnt].d == a[i].d && a[cnt].r == a[i].r) a[cnt].h = max(a[cnt].h, a[i].h);
        else a[++cnt] = a[i];
    }
    n = cnt;
}

ll getmax(int p) {
    ll ans = 0;
    for (; p > 0; p -= p & (-p)) ans = max(ans, bit[p]);
    return ans;
}

void update(int p, ll val) {
    for (; p <= n; p += p & (-p)) bit[p] = max(bit[p], val);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    while (n != 0) {
        for (int i = 0, x, y, z; i < n; ++i) {
//            cin >> tmp[0] >> tmp[1] >> tmp[2];
//            sort(tmp, tmp + 3);
//            a[i * 3 + 1] = mblock(tmp[0], tmp[1], tmp[2]);
//            a[i * 3 + 2] = mblock(tmp[0], tmp[2], tmp[1]);
//            a[i * 3 + 3] = mblock(tmp[1], tmp[2], tmp[0]);
            cin >> x >> y >> z;
            a[i * 3 + 1] = mblock(x, y, z);
            a[i * 3 + 2] = mblock(x, z, y);
            a[i * 3 + 3] = mblock(y, z, x);
        } n *= 3;

        sort(a + 1, a + n + 1);
        compressA();

        for (int i = 1; i <= n; ++i) b[i] = pii(a[i].r, i);
        sort(b + 1, b + n + 1, [](const pii& x, const pii& y) {
            return (x.first < y.first || (x.first == y.first && x.second > y.second));
        });

        for (int i = 1, ii; i <= n; ++i) {
            ii = b[i].second;
            dp[ii] = getmax(ii - 1) + a[ii].h;
            update(ii, dp[ii]);
        }
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
        fill(bit + 1, bit + n + 1, 0);
        cin >> n;
    }
    return 0;
}
    