// DOANCON

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
const int N = 2e5 + 8;
int n;
ll a[N];

int dp[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test; cin >> test; while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        dp[n] = 1;
        for (int i = n - 1; i; --i)
            if (a[i] * a[i + 1] < 0)
                dp[i] = dp[i + 1] + 1;
            else dp[i] = 1;

        for (int i = 1; i <= n; ++i)
            cout << dp[i] << ' ';
        cout << '\n';
    }
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    