// DPSEGINC

#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
const int N = 6006;
int n, dp[N];
ll a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
	fill(dp + 1, dp + n + 1, 1);

	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (a[i] % a[j] == 0) dp[i] = max(dp[i], dp[j] + 1);

	int pos = 1;
	for (int i = 2; i <= n; ++i) if (dp[i] > dp[pos]) pos = i;

	stack<int> ans;
	while (pos > 0) {
		ans.push(pos);
		int noww = pos;
		while (--pos > 0) if (dp[noww] == dp[pos] + 1 && a[noww] % a[pos] == 0) break;
	}

	cout << ans.size() << '\n';
	while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
	return 0;
}
    