// BTKSCORE

#include <iostream>
using namespace std;
typedef long long ll;
const int S = 1006, K = 22, N = 22;
int s, k, n, a[K][N], ans[K];
bool dp[S][K][N];

int check() {
    for (int i = 1; i <= n; ++i)
        if (dp[s][k][i]) return i;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s >> k >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) cin >> a[j][i];

    for (int j = 1; j <= n; ++j) dp[0][0][j] = true;

    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                if (a[i][j] >= a[i - 1][k]) {
                    for (int sum = a[i][j]; sum <= s; ++sum)
                        dp[sum][i][j] |= dp[sum - a[i][j]][i - 1][k];
                }
    
    int jj = check();
    if (jj > 0) {
        cout << "YES\n";
        int i = k;
        while (s > 0) {
            for (int j = 1; j <= n; ++j)
                if (a[i - 1][j] <= a[i][jj] && dp[s - a[i][jj]][i - 1][j]) {
                    ans[i] = a[i][jj];
                    s -= a[i][jj];
                    jj = j;
                    break;
                }
            --i;
        }
        for (int i = 1; i <= k; ++i) cout << ans[i] << ' ';
    }
    else cout << "NO";
    return 0;
}
    