// DPRCPAR

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const int N = 106;
string s;
int k, n;
long long z, dp[N][N], pow10[12];

template <typename T>
inline void readInt(T& num) {
	register char c = cin.get();
	while (c != '-' && ('0' > c || c > '9')) c = cin.get();
	for (num = 0; '0' <= c && c <= '9'; c = cin.get())
		num = (num << 1) + (num << 3) + c - '0';
}

void buildpow10() {
	pow10[0] = 1;
	for (int i = 1; i < 12; ++i) pow10[i] = (pow10[i - 1] << 1) + (pow10[i - 1] << 3);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	buildpow10();
	int t; readInt(t);
	while (t-- > 0)
	{
		readInt(k); readInt(z); cin >> s;
		n = s.size(); s = " " + s;

		for (int i = 0; i <= n; ++i)
			for (int s = 0; s <= k; ++s) dp[i][s] = -1;
		dp[0][0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			ll sum = 0;
			for (int j = i; j > 0; --j)
			{
				sum += pow10[i - j] * (s[j] - 48);
				if (sum <= z)
				{
					for (int s = 1; s <= k; ++s)
						if (dp[j - 1][s - 1] != -1)
							dp[i][s] = max(dp[i][s], dp[j - 1][s - 1] + sum);
				}
			}
		}
		cout << dp[n][k] << '\n';
	}
}
    