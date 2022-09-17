// TAMGIAC

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const int N = 1e4 + 7;
int n;
ll a[N], cnt[N], prf[N];

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
    for (int i = 1; i < N; ++i) prf[i] = prf[i - 1] + cnt[i];

    ll nhon(0), vuong(0), tu(0);
    for (int x = 1; x < N; ++x) if (cnt[x]) {
        int b = 0;
        { // xet x = y = z
            nhon += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) / 6;
        }
        { // xet x = y < z < 2x
            ll k = cnt[x] * (cnt[x] - 1) / 2;
            double tmp = sqrt(x * x + x * x);
            int i = tmp;
            if (i == tmp) {
                nhon += k * max(0LL, prf[i - 1] - prf[x]);
                vuong += k * cnt[i];
                tu += k * max(0LL, prf[x * 2 - 1] - prf[i]);
            }
            else {
                nhon += k * (prf[i] - prf[x]);
                tu += k * max(0LL, prf[x * 2 - 1] - prf[i]);
            }
        }

        // x < y
        for (int y = x + 1; y < N; ++y) if (cnt[y]) {
            { // xet x < y = z
                nhon += cnt[x] * cnt[y] * (cnt[y] - 1) / 2;
            }

            // xet x < y < z < x + y
            ll k = cnt[x] * cnt[y];
            double tmp = sqrt(x * x + y * y);
            int i = tmp;
            if (i == tmp) {
                nhon += k * max(0LL, prf[i - 1] - prf[y]);
                vuong += k * max(0LL, cnt[i]);
                tu += k * max(0LL, prf[x+y-1] - prf[i]);
            }
            else {
                nhon += k * max(0LL, prf[i] - prf[y]);
                tu += k * max(0LL, prf[x + y - 1] - prf[i]);
            }
        }
    }

    cout << nhon << ' ' << vuong << ' ' << tu << '\n';
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    