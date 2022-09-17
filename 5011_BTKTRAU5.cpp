// BTKTRAU5

#include <iostream>
#include <unordered_map>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 23;
int n, a[N];
unordered_map<ll, ll> a1, a2;

void Try1(int i, ll s1, ll s2) {
    if (i > n / 2) {
        a1[s1 - s2] = max(a1[s1 - s2], s1 + s2);
        return;
    }
    Try1(i + 1, s1 + a[i], s2);
    Try1(i + 1, s1, s2 + a[i]);
    Try1(i + 1, s1, s2);
}

void Try2(int i, ll s1, ll s2) {
    if (i > n) {
        a2[s1 - s2] = max(a2[s1 - s2], s1 + s2);
        return;
    }
    Try2(i + 1, s1 + a[i], s2);
    Try2(i + 1, s1, s2 + a[i]);
    Try2(i + 1, s1, s2);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Try1(1, 0, 0);
    Try2(n / 2 + 1, 0, 0);

    ll ans = 0, num;
    for (const pll& x : a1) {
        num = x.ff;
        if (a2.count(-num)) ans = max(ans, x.ss + a2[-num]);
    }
    cout << ans / 2;
    return 0;
}
    