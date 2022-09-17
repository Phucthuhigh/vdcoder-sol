// GRERANINC

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = (int)1e7 + 6;
int n, t, l[N], r[N], cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1, pre = 0, a; i <= n; ++i, pre = a) {
        cin >> a;
        if (a > pre) {
            for (int j = 0; j < a - pre; ++j) l[++t] = i;
        }

        if (a < pre) {
            for (int j = 0; j < pre - a; ++j) r[++cnt] = i - 1;
        }
    }

    while (cnt < t) r[++cnt] = n;
    cout << t << '\n';
    for (int i = 1; i <= t; ++i) cout << l[i] << ' ' << r[i] << '\n';
    return 0;
}
    