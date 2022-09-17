// PHNT

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_set>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 7, base = 311;
int n;
char s[N];
ll pw[N], h[N];
ll get(int l, int r) {
    return h[r] - h[l - 1] * pw[r - l + 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> (s + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * base;
        h[i] = h[i - 1] * base + s[i];
    }

    for (int k = 1; k <= n; ++k) {
        bool flag(true);
        unordered_set<ll> s;
        for (int r = k; r <= n; ++r) {
            ll x = get(r - k + 1, r);
            if (s.count(x)) {
                flag = false;
                break;
            }
            s.insert(x);
        }
        if (flag) {
            cout << k;
            return 0;
        }
    }
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    