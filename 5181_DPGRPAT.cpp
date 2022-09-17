// DPGRPAT

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 106, mod = 1e9;
int m, n, a[N][N], dp[N][N];

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];

    for (int i = 1; i <= m; ++i) dp[i][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j < n; ++j)
            for (int p = i; p <= m; ++p)
                for (int q = j; q <= n; ++q)
                    if (i + j < p + q && gcd(a[i][j], a[p][q]) > 1) (dp[p][q] += dp[i][j]) %= mod;

    int ans = 0;
    for (int i = 1; i <= m; ++i) (ans += dp[i][n]) %= mod;
    cout << ans;
}
    