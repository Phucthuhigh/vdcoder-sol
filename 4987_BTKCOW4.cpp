// BTKCOW4

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

const int N = 20, stt[16] = { 0, 1, 8, 9, 10, 11, 12, 13, 14, 15, 2, 3, 4, 5, 6, 7 };
typedef pair<int, int> pii;
int n, a[N];
ll sum, res;
vector<pii> path;
set<vector<pii>> s;

void Try(int i, ll s1, ll s2) {
    if (i > n) {
        if (s1 == s2) res = max(res, s1);
        return;
    }
    Try(i + 1, s1 + a[i], s2);
    Try(i + 1, s1, s2 + a[i]);
    Try(i + 1, s1, s2);
}

void Try2(int i, ll s1, ll s2) {
    if (i > n) {
        if (s1 == s2 && s1 == res) s.insert(path);
        return;
    }
    Try2(i + 1, s1 + a[i], s2);
    Try2(i + 1, s1, s2 + a[i]);

    path.emplace_back(stt[i], i);
    Try2(i + 1, s1, s2);
    path.pop_back();
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    Try(1, 0, 0);
    cout << res * 2 << '\n';
    if (res * 2 == sum) cout << "OK";
    else {
        Try2(1, 0, 0);
        for (vector<pii> vt : s) {
            for (pii& x : vt) cout << x.ss << ' '; 
            cout << '\n';
        }
    }
    return 0;
}
    