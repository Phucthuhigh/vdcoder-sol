// QUATANG

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
int n, x;
int a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    int ans(0);
    for (int i = 1, j = n; i < j; ++i) {
        while (i < j && a[i] + a[j] > x) --j;
        if (i < j) ans = max(ans, a[i] + a[j]);
    }
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    