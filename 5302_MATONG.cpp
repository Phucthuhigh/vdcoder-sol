// MATONG

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 8;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    ll ans(0);
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        for (int i = 1; i * i <= a; ++i) if (a % i == 0) ans += a + a;
        if (sqrt(a) == trunc(sqrt(a))) ans -= a;
    }
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    