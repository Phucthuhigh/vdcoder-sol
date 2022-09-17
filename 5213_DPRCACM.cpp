// DPRCACM

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 2004, mod = (int)1e9 + 7;
int n, k, dp[N][N];
bool avail[N][N];
vector<int> g[N];

void buildG()
{
	for (int i = 1, j; i <= n; ++i)
	{
		j = 1;
		while (j * j < i)
		{
			if (i % j == 0)
			{
				g[i].push_back(j);
				g[i].push_back(i / j);
			}
			++j;
		}
		if (j * j == i) g[i].push_back(j);
	}
}

int dprc(int n, int k)
{
	if (k == 0) return 1;
	if (avail[n][k]) return dp[n][k];

	avail[n][k] = true;
	for (int i : g[n])
		(dp[n][k] += dprc(i, k - 1)) %= mod;
	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	buildG();
	int res = 0;
	for (int i = 1; i <= n; ++i)
		(res += dprc(i, k - 1)) %= mod;
	cout << res;

	return 0;
}
    