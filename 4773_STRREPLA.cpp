// STRREPLA

#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const short N = 1006;
int n, m, num_s[26], dp[N][26];
string s;
char c;

int query(int m, const char& c) {
	int ans = 0;
	for (int l = 0, r = 0; r < n; ++r) {
		if (c != s[r]) --m;
		while (m < 0) {
			if (c != s[l]) ++m;
			++l;
		}
		ans = max(ans, r - l + 1);
	}
	return ans;
}

void init() {
	for (const char& c : s) ++num_s[c - 'a'];
	for (int i = 0; i < 26; ++i)
		for (int m = 0; m <= n - num_s[i]; ++m) dp[m][i] = -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> s;
	init();
	int q; cin >> q; while (q-- > 0) {
		cin >> m >> c;
		m = min(m, n - num_s[c - 'a']);
		if (dp[m][c - 'a'] == -1) dp[m][c - 'a'] = query(m, c);
		cout << dp[m][c - 'a'] << '\n';
	}
}
    