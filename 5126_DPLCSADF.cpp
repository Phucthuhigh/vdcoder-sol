// DPLCSADF

#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
const int N = 302;
string s, t;
int m, n, dp[N][N];
bool trace[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int test; cin >> test; while (test-- > 0) {
		cin >> s >> t; m = s.size(), n = t.size(); s = " " + s, t = " " + t;

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else {
					trace[i][j] = (dp[i - 1][j] > dp[i][j - 1]);
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}

		stack<char> ans;
		int i = m, j = n;
		while (i > 0 && j > 0) {
			if (s[i] == t[j]) ans.push(s[i]), --i, --j;
			else {
				if (trace[i][j]) ans.push(s[i--]);
				else ans.push(t[j--]);
			}
		}
		while (i > 0) ans.push(s[i--]);
		while (j > 0) ans.push(t[j--]);

		while (!ans.empty()) cout << ans.top(), ans.pop();
		cout << '\n';
	}
	return 0;
}
    