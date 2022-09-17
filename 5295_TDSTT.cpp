// TDSTT

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
const int N = 1e5 + 9;

int f[N], pr[N], cnt;
vector<int> g[N];
void init() {
    for (int i = 2; i < N; ++i) {
        if (!f[i]) f[i] = pr[cnt++] = i;
        for (int j = 0; j < cnt && pr[j] <= f[i] && i * pr[j] < N; ++j)
            f[i * pr[j]] = pr[j];
    }

    for (int i = 2, x, tmp; i < N; ++i) {
        x = i;
        while (x > 1) {
            tmp = f[x];
            g[i].push_back(tmp);
            while (f[x] == tmp) x /= tmp;
        }
    }
}

int n, dp[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    init();
    cin >> n;
    for (int i = 1, x, tmp; i <= n; ++i) {
        cin >> x;
        tmp = 0;
        for (int u : g[x]) tmp = max(tmp, dp[u]);
        for (int u : g[x]) dp[u] = max(dp[u], tmp + 1);
    }
    cout << *max_element(dp + 1, dp + N);
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
    