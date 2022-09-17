// BRUOLANG

#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
int n, m, k, a[N];
struct Data {
    int x, y;
    ll w;
} turn12[N];
int turn3[N];
ll turn_all[N], prf[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1, sign; i <= m; ++i) {
        cin >> sign >> turn12[i].x >> turn12[i].y >> turn12[i].w;
        if (sign == 2) turn12[i].w = -turn12[i].w;
    }

    for (int i = 1, t, x, y; i <= k; ++i) {
        cin >> t >> x >> y;
        ++turn3[x];
        --turn3[y + 1];
    }

    ll sum(0);
    for (int i = 1; i <= m; ++i) {
        sum += turn3[i];
        turn12[i].w *= sum;
        turn_all[turn12[i].x] += turn12[i].w;
        turn_all[turn12[i].y + 1] -= turn12[i].w;
    }

    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += turn_all[i];
        prf[i] = prf[i - 1] + sum + a[i];
    }

    int x1, y1, s1, x2, y2, s2;
    cin >> x1 >> y1 >> s1 >> x2 >> y2 >> s2;
    ll sum1 = abs(prf[y1] - prf[x1 - 1] - s1), sum2 = abs(prf[y2] - prf[x2 - 1] - s2);
    if (sum1 < sum2) cout << "SAN WIN";
    if (sum1 > sum2) cout << "MI WIN";
    if (sum1 == sum2) cout << "HOA";
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    