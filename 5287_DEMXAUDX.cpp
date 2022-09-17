// DEMXAUDX

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
const int N = 1003;
int n, test;
char s[N];

ll dp[N][N];
bool a[N][N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> test >> (s + 1);

    for (int l = n; l; --l) {
        dp[l][l] = 1;
        a[l][l] = a[l + 1][l] = true;
        for (int r = l + 1; r <= n; ++r) {
            dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1];
            if (s[l] == s[r] && a[l + 1][r - 1]) {
                a[l][r] = true;
                ++dp[l][r];
            }
        }
    }

    int l, r; while (test--) {
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    