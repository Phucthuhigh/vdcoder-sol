// DPRCUT

#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

const int N = 56;
int l, n, c[N];
int dp[N][N];
bool was[N][N];

template <typename T>
inline void readInt(T& num) {
	register char c = getchar();
	while (c != '-' && (c < '0' || '9' < c)) c = getchar();
	for (num = 0; '0' <= c && c <= '9'; c = getchar())
		num = (num << 1) + (num << 3) + c - '0';
}

void process() {
	for (int i = 2; i <= n; ++i) dp[i - 2][i] = c[i] - c[i - 2];
	for (int len = 3; len <= n; ++len)
		for (int i = 0, j = len; j <= n; ++i, ++j) {
			dp[i][j] = 1e9;
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = min(dp[i][j], c[j] - c[i] + dp[i][k] + dp[k][j]);
		}
	cout << dp[0][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	readInt(l);
	while (l != 0) {
		readInt(n);	for (int i = 1; i <= n; ++i) readInt(c[i]); c[++n] = l;
		process();
		readInt(l);
	}
}
    