// GREEXAM2

#include <iostream>
#include <algorithm>

using namespace std;
const int N = (int)2e5 + 8;
int n, t;
struct problem {
    int a, t, id;
} a[N];

bool check(int x) {
    int dem = 0;
    for (int i = 1, sum = 0; i <= n && sum + a[i].t <= t; ++i)
        if (a[i].a >= x) ++dem, sum += a[i].t;
    return (dem >= x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i].a >> a[i].t, a[i].id = i;
    sort(a + 1, a + n + 1, [](const problem& x, const problem& y) {
        return (x.t < y.t || (x.t == y.t && x.a < y.a));
    });

    int mid, l = 1, r = n, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n' << ans << '\n';
    
    int block = ans;
    for (int i = 1, sum = 0; i <= n && sum + a[i].t <= t && ans > 0; ++i)
        if (a[i].a >= block) cout << a[i].id << ' ', sum += a[i].t, --ans;
    
    return 0;
}
    