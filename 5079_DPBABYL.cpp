// DPBABYL

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 506;
int n;
long long dp[N * 6];
struct block {
    int d, r, h;
    bool operator < (const block& other) const {
        return (d < other.d || (d == other.d && r > other.r));
    }
} a[N * 6];

block mblock(int a, int b, int c) {
    block k; k.d = a, k.r = b, k.h = c;
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    while (n != 0) {
        for (int i = 0, x, y, z; i < n; ++i) {
            cin >> x >> y >> z;
            a[i * 6 + 1] = mblock(x, y, z);
            a[i * 6 + 2] = mblock(x, z, y);
            a[i * 6 + 3] = mblock(y, x, z);
            a[i * 6 + 4] = mblock(y, z, x);
            a[i * 6 + 5] = mblock(z, x, y);
            a[i * 6 + 6] = mblock(z, y, x);
        } n *= 6;

        sort(a + 1, a + n + 1);
        compressA();

        for (int i = 1; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 1; j < i; ++j)
                if (a[j].r < a[i].r) dp[i] = max(dp[i], dp[j]);
            dp[i] += a[i].h;
        }
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
        cin >> n;
    }
    return 0;
}
    