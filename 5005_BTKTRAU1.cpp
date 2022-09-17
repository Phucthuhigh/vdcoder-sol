// BTKTRAU1

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 34;
int n;
int a[N];
ll s;

int cntb = 1, cntc = 1;
ll b[1 << 20], c[1 << 20];
void prep() {
    int n1 = n >> 1;
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= cntb; ++j)
            b[j + cntb] = b[j] + a[i];
        cntb <<= 1;
    }

    for (int i = n1 + 1; i <= n; ++i) {
        for (int j = 1; j <= cntb; ++j)
            c[j + cntc] = c[j] + a[i];
        cntc <<= 1;
    }
}

bool check() {
    sort(c + 1, c + cntc + 1);
    for (int i = 1; i <= cntb; ++i)
        if (binary_search(c + 1, c + cntc + 1, s - b[i])) return true;
    return false;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    prep();
    cout << (check() ? "YES" : "NO");
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    