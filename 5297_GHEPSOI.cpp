// GHEPSOI

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#define ff     first
#define ss     second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 8;
int n;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        q.push(x);
    }

    ll ans(0), a, b;
    while (q.size() > 1) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += a + b;
        q.emplace(a + b);
    }
    cout << ans;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    