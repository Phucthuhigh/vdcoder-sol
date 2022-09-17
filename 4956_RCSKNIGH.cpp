// RCSKNIGH

#include <iostream>
#include <algorithm>
#include <queue>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
typedef short int sint;
const sint N = 11, dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 }, dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
bool avail[N][N];
int dp[N][N][N];
sint num, n;

void Try(sint x, sint y, sint h)
{
	for (sint i = 0, u, v; i < 8; ++i)
	{
		u = x + dx[i], v = y + dy[i];
		if (0 < u && u < 11 && 0 < v && v < 11)
		{
			if (h < n) Try(u, v, h + 1);
			else if (avail[u][v])
			{
				avail[u][v] = false;
				++num;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	sint t, x, y; cin >> t;
	while (t-- > 0)
	{
		cin >> x >> y >> n;
		if (n > 5)
		{
			cout << "50\n";
			continue;
		}

		if (dp[x][y][n])
		{
			cout << dp[x][y][n] << '\n';
			continue;
		}

		for (sint i = 1; i < 11; ++i)
			for (sint j = 1; j < 11; ++j) avail[i][j] = true;
		num = 0;
		Try(x, y, 1);
		dp[x][y][n] = dp[y][x][n] = dp[11 - y][x][n] = dp[y][11 - x][n] = num;
		x = 11 - x, y = 11 - y;
		dp[x][y][n] = dp[y][x][n] = dp[11 - y][x][n] = dp[y][11 - x][n] = num;
		cout << num << '\n';
	}

	return 0;
}
    