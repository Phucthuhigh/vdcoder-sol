// DPRENTMA2

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
pii a[N];
map<int, int> dp;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i].ss >> a[i].tt;
    sort(a + 1, a + n + 1);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[a[i].tt] = max(dp[a[i - 1].tt], prev(dp.lower_bound(a[i].ss))->second + (a[i].tt - a[i].ss + 1));
    }
    cout << dp[a[n].tt];
    return 0;
}
    