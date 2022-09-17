// GREKMULTI

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define ff first
#define ss second
#define eb emplace_back
using namespace std;
typedef long long ll;
int n, k, a[30], dp[30];
unordered_map<int, vector<int>> m;
unordered_map<int, int> ma;

int sol(int num, const vector<int>& x) {
	int nn = ma[num];
	for (int i = 0; i <= nn; ++i) a[i] = 0;
	for (const int& y : x) ++a[y];
	if (nn == 0) return a[0];
	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);
	for (int i = 2; i <= nn; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	return dp[nn];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	if (k == 1) {
		unordered_set<int> s;
		for (int i = 0, x; i < n; ++i) cin >> x, s.insert(x);
		cout << s.size();
	}
	else {
		for (int i = 0, x, d; i < n; ++i) {
			cin >> x;
			d = 0;
			while (x % k == 0) x /= k, ++d;
			m[x].eb(d);
			ma[x] = max(ma[x], d);
		}
		int ans = 0;
		for (unordered_map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
			ans += sol(it->ff, it->ss);
		}
		cout << ans;
	}
	return 0;
}
    