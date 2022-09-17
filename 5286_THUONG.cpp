// THUONG

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
const int N = 302;
int m, n;
int a[N][N];

int dp[N][N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];

    for (int i = 1; i <= m; ++i) dp[i][1] = a[i][1];
    for (int j = 2; j <= n; ++j) {
        dp[0][j] = dp[m + 1][j] = -1e9;
        for (int i = 1; i <= m; ++i)
            dp[i][j] = max({ dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1] }) + a[i][j];
    }

    int ans(dp[1][n]);
    for (int i = 2; i <= m; ++i) ans = max(ans, dp[i][n]);
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    