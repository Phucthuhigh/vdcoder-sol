// DPLCSAD

#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1020;
string s, t;
int m, n, dp1[N][N], dp2[N][N];
bool was[N][30];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s >> t;
	m = s.size(), n = t.size();
	s = " " + s, t = " " + t;

	int res = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			dp1[i][j] = (s[i] == t[j] ? dp1[i - 1][j - 1] + 1 : max(dp1[i][j - 1], dp1[i - 1][j]));

	for (int i = m; i > 0; --i)
		for (int j = n; j > 0; --j)
			dp2[i][j] = (s[i] == t[j] ? dp2[i + 1][j + 1] + 1 : max(dp2[i][j + 1], dp2[i + 1][j]));

	int block = dp1[m][n]; // longest common substring
	for (int i = 0; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (dp1[i][j - 1] + dp2[i + 1][j + 1] == block && !was[i][t[j] - 'a']) // insert in the middle i & i+1 a char is t[j]
				was[i][t[j] - 'a'] = true, ++res;

	cout << res;
	return 0;
}
    