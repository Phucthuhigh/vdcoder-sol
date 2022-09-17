// GREBALLZ

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1000;
int n;

struct team {
    ll t, w;
    bool operator < (const team& other) const {
        return t > other.t;
    }
} a[N];

struct cmp {
    bool operator() (const team& A, const team& B) {
        return A.w - A.t > B.w - B.t;
    }
};

void minimize(int& a, int b) { if (a > b) a = b; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> a[i].t >> a[i].w;
    sort(a + 1, a + n);

    priority_queue<team, vector<team>, cmp> q;
    int L = 1;
    while (L < n && a[L].t > a[0].t) q.emplace(a[L++]);

    int ans = q.size() + 1;
    while (a[0].t > 0 && !q.empty()) {
        team p = q.top(); q.pop();
        if (a[0].t < p.w - p.t + 1) break;
        a[0].t -= p.w - p.t + 1;

        while (L < n && a[L].t > a[0].t) q.emplace(a[L++]);
        minimize(ans, q.size() + 1);
    }
    cout << ans;
}
    