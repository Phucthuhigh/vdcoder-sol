// GRESEG

#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct segment {
    int s, d, id;
} s[300005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i].s >> s[i].d, s[i].id = i;
    sort(s + 1, s + n + 1, [](const segment& x, const segment& y) { return x.s < y.s || (x.s == y.s && x.d > y.d); });
    for (int i = 2; i <= n; ++i) // giam ngat
    {
        if (s[i].d <= s[i - 1].d)
        {
            cout << s[i].id << ' ' << s[i - 1].id;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
    