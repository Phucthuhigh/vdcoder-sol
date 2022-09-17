// QUASONG

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 8, mod = 1000000007;
int n, k;
pii a[12];

int prf[N], dp[N];
int get(int l, int r) {
    if (r < 1) return 0;
    return (prf[r] - prf[max(l, 1) - 1] + mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) cin >> a[i].ff >> a[i].ss;
    sort(a + 1, a + k + 1);

    int sz(1);
    for (int i = 2; i <= k; ++i) {
        if (a[sz].ss >= a[i].ff)
            a[sz].ss = max(a[sz].ss, a[i].ss);
        else a[++sz] = a[i];
    }

    dp[1] = prf[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= sz; ++j)
            (dp[i] += get(i - a[j].ss, i - a[j].ff)) %= mod;
        prf[i] = (prf[i - 1] + dp[i]) % mod;
    }
    cout << dp[n];
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    