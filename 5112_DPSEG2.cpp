// DPSEG2

#include <iostream>
#include <algorithm>
#include <map>
#define tt first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = (int)1e5 + 9, oo = (int)1e9;
int n, a[N], b[N], cnt;
pii s[N];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> s[i].first >> s[i].second, s[i].second = oo - s[i].second;
	sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) a[i] = s[i].second;

	for (int i = 1, pos; i <= n; ++i) {
		pos = upper_bound(b, b + cnt, a[i]) - b;
		if (pos == cnt) b[cnt++] = a[i];
		else b[pos] = a[i];
	}
	cout << cnt;
    return 0;
}
    