// BTKSUMDIV2

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimization ("O3")
#include <iostream>
#include <unordered_map>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 42;
int n, a[N], cnt;
ll k, s;
unordered_map<ll, int> a1, a2;

void Try1(int i) {
    if (i > n / 2) {
        a1[s % k] = max(a1[s % k], cnt);
        return;
    }
    s += a[i], ++cnt;
    Try1(i + 1);
    s -= a[i], --cnt;
    Try1(i + 1);
}

void Try2(int i) {
    if (i > n) {
        a2[s % k] = max(a2[s % k], cnt);
        return;
    }
    s += a[i], ++cnt;
    Try2(i + 1);
    s -= a[i], --cnt;
    Try2(i + 1);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Try1(1);
    Try2(n / 2 + 1);

    int ans = 0;
    for (const pli& x : a1) {
        ll num = (x.ff == 0 ? 0 : k - x.ff);
        if (a2.count(num)) ans = max(ans, x.ss + a2[num]);
    }
    cout << ans;
    return 0;
}
    