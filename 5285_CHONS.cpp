// CHONS

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#include<bitset>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 9;
bitset<N> b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    b[0] = 1;

    int n; cin >> n;
    for (int i = 0, x; i < n; ++i)
        cin >> x, b |= b << x;
    cout << b.count() - 1;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    