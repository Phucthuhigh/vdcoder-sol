// DUANGUA

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
int k, n;
int s[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    sort(s + 1, s + n + 1, greater<int>());

    ll ans(0);
    for (int i = 1; i <= k; ++i)
        ans += s[i * 2 - 1] * s[i << 1];
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    