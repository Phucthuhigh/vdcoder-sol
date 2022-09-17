// DPKNSTE2

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
const int N = 102, M = 10004;
int m, n, dp[2][M];
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1, w, v, a, bit1 = 1, bit0 = 0; i <= n; ++i, swap(bit1, bit0)) {
		cin >> w >> v >> a;
		if (w == 0) {
			for (int j = 0; j <= m; ++j) dp[bit1][j] = dp[bit0][j] + v * a;
			continue;
		}

		for (int j = 0; j < w; ++j) {
			for (int k = j; k <= m; k += w) {
				while (!dq.empty() && dq.front() < k - a * w) dq.pop_front();
				while (!dq.empty() && dp[bit0][dq.back()] + (k - dq.back()) / w * v <= dp[bit0][k]) dq.pop_back();
				dq.push_back(k);
				dp[bit1][k] = dp[bit0][dq.front()] + (k - dq.front()) / w * v;
			}
			dq.clear();
		}
	}
	cout << max(*max_element(dp[0], dp[0] + m + 1), *max_element(dp[1], dp[1] + m + 1));
}
    