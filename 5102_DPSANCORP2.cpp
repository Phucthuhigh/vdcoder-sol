// DPSANCORP2

#include <iostream>
#include <algorithm>
#include <map>
#define tt first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)1e5 + 9;
int n;
struct order {
    int s, t, p;
} a[N];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t-- > 0) {
        cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i].s >> a[i].t >> a[i].p, a[i].t += a[i].s - 1;
        sort(a + 1, a + n + 1, [](const order& x, const order& y) {
            return (x.t < y.t);
            });

        map<int, ll> dp;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[a[i].t] = max(dp[a[i - 1].t], prev(dp.lower_bound(a[i].s))->second + (a[i].p));
        }
        cout << dp[a[n].t] << '\n';
    }
    return 0;
}
    