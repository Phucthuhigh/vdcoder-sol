// DPMI

#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <string>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 3006, mod = (int)1e8;
int n;
pii a[N];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while (n != -1) {
		for (int i = 1; i <= n; ++i) cin >> a[i].ss >> a[i].ff;
		sort(a + 1, a + n + 1);

		map<int, int> dp;
		dp[0] = 0;
		for (int i = 1, l, r; i <= n; ++i) {
			tie(r, l) = a[i];
			if (!dp.count(r)) dp[r] = prev(prev(dp.end()))->ss;
			dp[r] += prev(dp.upper_bound(l))->ss + 1;
			if (dp[r] >= mod) dp[r] -= mod;
		}

		string ans = to_string(prev(dp.end())->ss);
		while (ans.size() < 8) ans = "0" + ans;
		cout << ans << '\n';
		cin >> n;
	}
	
	return 0;
}
    