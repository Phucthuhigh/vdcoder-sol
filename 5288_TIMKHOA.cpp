// TIMKHOA

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

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k, ans; cin >> k >> ans;
    for (int i = 1, x; i < k; ++i) {
        cin >> x;
        ans = gcd(ans, x);
    }
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    