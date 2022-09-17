// RCSMATMA

#include <iostream>
#include <algorithm>
#include <queue>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = 26, dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

int m, n, a[N][N], dp[N][N], res, num;
bool avail[N][N];

void Try(int x, int y)
{
	++num; res = max(res, num); avail[x][y] = true;
	for (int i = 0, u, v; i < 4; ++i)
	{
		u = x + dx[i], v = y + dy[i];
		if (1 <= u && u <= m && 1 <= v && v <= n)
			if (a[u][v] >= a[x][y] && !avail[u][v]) Try(u, v);
	}
	--num; avail[x][y] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> m >> n;
	char c;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> c;
			a[i][j] = c - 'A' + 1;
		}

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			Try(i, j);

	cout << res;
	return 0;
}
    