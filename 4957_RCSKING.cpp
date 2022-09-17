// RCSKING

#include <iostream>
#include <algorithm>
#include <queue>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = 1006, dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int m, n, u1, v1, u2, v2, sx, sy, x, y;
bool avail[N][N];

void cantjoin(int x, int y)
{
	for (int i = 1; i <= n; ++i) avail[x][i] = avail[i][y] = true;
	for (int i = x, j = y; i <= n && j <= n; ++i, ++j) avail[i][j] = true;
	for (int i = x, j = y; i >= 1 && j >= 1; --i, --j) avail[i][j] = true;
	for (int i = x, j = y; i <= n && j >= 1; ++i, --j) avail[i][j] = true;
	for (int i = x, j = y; i >= 1 && j <= n; --i, ++j) avail[i][j] = true;
}

void bfs()
{
	queue<int> qx, qy;
	qx.push(sx), qy.push(sy);
	avail[sx][sy] = true;
	while (!qx.empty())
	{
		sx = qx.front(), sy = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0, u, v; i < 8; ++i)
		{
			u = sx + dx[i], v = sy + dy[i];
			if (1 <= u && u <= n && 1 <= v && v <= n)
				if (!avail[u][v])
				{
					avail[u][v] = true;
					qx.push(u), qy.push(v);
				}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> u1 >> v1 >> u2 >> v2 >> sx >> sy >> x >> y;
	cantjoin(u1, v1);
	cantjoin(u2, v2);
	if (avail[x][y]) cout << "NO";
	else
	{
		bfs();
		cout << (avail[x][y] ? "YES" : "NO");
	}

	return 0;
}
    