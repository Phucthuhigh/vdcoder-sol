// CHONDUA

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 8;
int n;
unordered_map<int, ll> a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1, x; i <= n; ++i) cin >> x, ++a[x];
    for (int i = 1, x; i <= n; ++i) cin >> x, ++b[x];

    ll ans(0);
    for (auto it : a)
        ans += it.ss * (n - b[it.ff]);
    for (auto it : b)
        ans += it.ss * (n - a[it.ff]);
    cout << ans / 2;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    