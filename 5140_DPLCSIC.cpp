// DPLCSIC

#include <iostream>
using namespace std;

typedef long long ll;
const int N = 5006;
ll a[N], b[N];
int n, m, lcs[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m; for (int i = 1; i <= m; ++i) cin >> a[i];
    cin >> n; for (int j = 1; j <= n; ++j) cin >> b[j];

    for (int i = 1, cur; i <= m; ++i) {
        cur = 0; // luu nhung lcs co x < i && y < j
        for (int j = 1; j <= n; ++j) {
            lcs[i][j] = lcs[i - 1][j];
            if (a[i] == b[j]) lcs[i][j] = max(lcs[i][j], cur + 1);
            else if (a[i] > b[j]) cur = max(cur, lcs[i - 1][j]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, lcs[m][i]);
    cout << res;
    return 0;
}
    