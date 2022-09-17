// GRESMS

#pragma GCC otimization ("Ofast")
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
int n, k, m, a[N], x[N];
string s[N], ss;
unordered_map<string, int> mymap;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k >> m;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0, cnt, mi; i < k; ++i) {
		cin >> cnt;
		mi = 1e9;
		for (int j = 0; j < cnt; ++j) cin >> x[j], mi = min(mi, a[x[j]]);
		for (int j = 0; j < cnt; ++j) a[x[j]] = mi;
	}
	for (int i = 1; i <= n; ++i) mymap[s[i]] = a[i];
	ll cost = 0;
	for (int i = 0; i < m; ++i) {
		cin >> ss;
		cost += mymap[ss];
	}
	cout << cost;
	return 0;
}
    