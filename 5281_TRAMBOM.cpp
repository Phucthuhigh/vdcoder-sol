// TRAMBOM

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
int n, k;
int h[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    sort(h + 1, h + n + 1);

    int ans(h[n]);
    for (int i = k; i <= n; ++i)
        ans = min(ans, h[i] - h[i - k + 1]);
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    