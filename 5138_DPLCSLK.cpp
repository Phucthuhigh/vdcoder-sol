// DPLCSLK

#include <iostream>
#include <algorithm>
using namespace std;
int m, n, a[1003], b[1003], dp[1003][1003];
#define max4(a, b, c, d) max(max(a, b), max(c, d));
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 1, j = 1; i <= m; ++i) dp[i][j] = (a[i] == b[j] ? 1 : dp[i - 1][j]);
    for (int i = 1, j = 1; j <= n; ++j) dp[i][j] = (a[i] == b[j] ? 1 : dp[i][j - 1]);

    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= n; ++j)
            if (a[i] == b[j]) dp[i][j] = dp[i - 2][j - 2] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    cout << max4(dp[m][n], dp[m][n - 1], dp[m - 1][n], dp[m - 1][n - 1]);
    return 0;
}
    