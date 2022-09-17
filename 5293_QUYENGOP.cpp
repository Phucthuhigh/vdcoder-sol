// QUYENGOP

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
    ll n; cin >> n;
    ll x = sqrt(n);
    cout << n * (n + 1) / 2 - x * (x + 1) * (2 * x + 1) / 6;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    