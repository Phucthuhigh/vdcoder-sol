// DPGRRB2

// https://codeforces.com/blog/entry/16099 100589F
#include <iostream>
#include <algorithm>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1e5 + 9, P = 2006, mod = (int)1e9 + 7;
int m, n, p;
pii block[P] = { {1, 1} };

ll invmod(ll a, int modd) { // a ^ (mod - 2)
    modd -= 2;
    ll ans = 1, tmp = a;
    while (modd) {
        if (modd & 1) (ans *= tmp) %= mod;
        (tmp *= tmp) %= mod;
        modd >>= 1;
    }
    return ans;
}

ll fact[N << 1] = { 1, 1 }, invfact[N];
ll calc(pii s, pii e) {
    int x = e.ff - s.ff, y = e.ss - s.ss;
    return ((fact[x + y] * invfact[x]) % mod * invfact[y]) % mod;
}

ll ans[P];
void process() {
    for (int i = 2; i < m + n; ++i) fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 0, mn = max(m, n); i <= mn; ++i) invfact[i] = invmod(fact[i], mod);

    for (int i = 1; i <= p; ++i) ans[i] = calc(block[0], block[i]);
    for (int i = 1; i < p; ++i)
        for (int j = i + 1; j <= p; ++j) if (block[i].ff <= block[j].ff && block[i].ss <= block[j].ss) {
            (ans[j] -= ans[i] * calc(block[i], block[j])) %= mod;
            if (ans[j] < 0) ans[j] += mod;
        }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> m >> n >> p;
    for (int i = 1; i <= p; ++i) cin >> block[i].ff >> block[i].ss;
    block[++p] = pii(m, n);

    sort(block + 1, block + p + 1);
    process();
    cout << ans[p];
}
    