// DPRENTHT2

#include <iostream>
#include <algorithm>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 9;
int n, dp[N];
pii a[N];

void compress() {
    sort(a + 1, a + n + 1);
    int cnt = 1;
    for (int i = 2; i <= n; ++i) {
        while (cnt > 0 && a[cnt].ss > a[i].ss) --cnt; ++cnt;
        a[cnt] = a[i];
    }
    n = cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].ff >> a[i].ss;
    compress();

    for (int l = 0, r = 1; r <= n; ++r) {
        while (a[l + 1].ss < a[r].ff) ++l;
        dp[r] = max(dp[r - 1], dp[l] + 1);
    }
    cout << dp[n];
}
    