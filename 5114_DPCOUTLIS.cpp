// DPCOUTLIS

#pragma GCC optimize ("O3")
#include<iostream>
#include<algorithm>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 8, mod = 1e9 + 7;
int n, a[N];

int c[N], cnt;
void readData() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // compress
    copy(a + 1, a + n + 1, c + 1);
    sort(c + 1, c + n + 1);
    cnt = unique(c + 1, c + n + 1) - c;
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c;
}

void maximize(pii& A, const pii& B) {
    if (A.ff < B.ff) A = B;
    else if (B.ff == A.ff) {
        A.ss += B.ss;
        if (A.ss > mod) A.ss -= mod;
    }
}

pii bit[N];
void update(int p, pii val) { for (; p <= cnt; p += p & -p) maximize(bit[p], val); }
pii query(int p) {
    pii ans = pii(0, 1);
    for (; p; p -= p & -p) maximize(ans, bit[p]);
    return ans;
}

void process() {
    fill(bit + 1, bit + cnt + 1, pii(-1, 1));
    pii ans(0, 0);
    for (int i = 1; i <= n; ++i) {
        pii u = query(a[i] - 1); ++u.ff;
        maximize(ans, u);
        update(a[i], u);
    }
    cout << ans.ss;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    readData();
    process();
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    