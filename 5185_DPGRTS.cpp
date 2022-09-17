// DPGRTS

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
#define ff first
#define ss second

const int N = 100 + 5;
int m, n;
int a[N][N];
int dp[N][N][N];
pii trace[N][N][N];

bool maximize(int &a, int b) { return a < b ? a = b, true : false; }
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = j; k <= n; ++k) {
                for (int x = j - 1; x <= j + 1; ++x)
                    for (int y = max(x, k - 1); y <= k + 1; ++y)
                        if (maximize(dp[i][x][y], dp[i - 1][j][k] + a[i][x] + (x != y ? a[i][y] : 0)))
                            trace[i][x][y] = pii(j, k);
            }

    int ans(-1), x(0), y(0);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            if (maximize(ans, dp[m][i][j]))
                x = i, y = j;

    cout << ans << '\n';
    string s1, s2;
    for (int i = m; i > 1; --i) {
        pii j = trace[i][x][y];
        s1.push_back("LDR"[x - j.ff + 1]);
        s2.push_back("LDR"[y - j.ss + 1]);
        x = j.ff, y = j.ss;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //cout << x << ' ' << y << '\n' << s1 << '\n' << s2 << '\n';
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    