// GRETEAM2

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 1000;
int n, a[N], nxt[N], pre[N];
char c[N];
bool was[N];

struct Data {
    int diff, p1, p2;
    bool operator < (const Data& other) const { // i mean >
        return diff > other.diff || (diff == other.diff && p1 > other.p1);
    }
};

int cnt, x1[N], x2[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) nxt[i] = i + 1;
    for (int i = 2; i <= n; ++i) pre[i] = i - 1;

    priority_queue<Data> q;
    for (int i = 1; i < n; ++i) {
        if (c[i] != c[nxt[i]]) q.push({ abs(a[i] - a[nxt[i]]), i, nxt[i] });
    }

    int p1, p2;
    while (!q.empty()) {
        p1 = q.top().p1, p2 = q.top().p2; q.pop();
        if (was[p1] || was[p2]) continue;
       
        ++cnt, was[x1[cnt] = p1] = true, was[x2[cnt] = p2] = true;
        if (!pre[p1] || !nxt[p2]) continue;
        p1 = pre[p1], p2 = nxt[p2];
        nxt[p1] = p2, pre[p2] = p1;
        if (c[p1] != c[p2]) q.push({ abs(a[p1] - a[p2]), p1, p2 });
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; ++i) cout << x1[i] << ' ' << x2[i] << '\n';
}
    