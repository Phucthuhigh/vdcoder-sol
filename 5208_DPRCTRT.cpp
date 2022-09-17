// DPRCTRT

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const int N = 102;
int n;
ll a[N], prf[N], dp[N][N];

template <typename T>
inline void readInt(T& num) {
	register char c = getchar();
	while (c != '-' && (c < '0' || '9' < c)) c = getchar();
	bool neg = (c == '-');
	if (c == '-') c = getchar();
	for (num = 0; '0' <= c && c <= '9'; c = getchar())
		num = (num << 1) + (num << 3) + c - '0';
	if (neg) num = -num;
}

void process() {
	for (int i = 1; i <= n; ++i) prf[i] = prf[i - 1] + a[i], dp[i][i] = a[i];
	for (int len = 2; len <= n; ++len)
		for (int i = 1, j = len; j <= n; ++i, ++j) {
			dp[i][j] = prf[j] - prf[i - 1];
			for (int k = i; k < j; ++k) // [i][k] - dp[k+1][j], [k+1][j] - dp[i][k]
				dp[i][j] = max(dp[i][j], max(prf[k] - prf[i - 1] - dp[k + 1][j], prf[j] - prf[k] - dp[i][k]));
		}
	cout << dp[1][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	while (true) {
		readInt(n); if (n == 0) break;
		for (int i = 1; i <= n; ++i) readInt(a[i]);
		process();
	}
}
    