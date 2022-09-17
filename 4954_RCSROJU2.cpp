// RCSROJU2

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int m, n;
pair<int, int> pre[502][502], R, J;
bool a[502][502];
char c;
pair<int, int> mov[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs()
{
	queue<pair<int, int>> q;
	q.push(J);
	a[J.first][J.second] = false;
	while (!q.empty())
	{
		pair<int, int> x = q.front(); q.pop();

		for (int i = 0, i1, j1; i < 4; ++i)
		{
			i1 = x.first + mov[i].first;
			j1 = x.second + mov[i].second;
			if (a[i1][j1])
			{
				pre[i1][j1] = x;
				a[i1][j1] = false;
				q.push({ i1, j1 });
			}
		}
	}
}

void output()
{
	pair<int, int> c = { 0, 0 };
	if (a[R.first][R.second] || J == c || R == c) cout << "NO";
	else
	{
		cout << "YES\n";

		queue<pair<int, int>> street;
		pair<int, int> x = R;
		while (x != J)
		{
			street.push(x);
			x = pre[x.first][x.second];
		}
		street.push(J);

		cout << street.size() << '\n';
		while (!street.empty())
		{
			pair<int, int> x = street.front(); street.pop();
			cout << x.first << ' ' << x.second << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> c;
			if (c != 'x')
			{
				a[i][j] = true;
				if (c == 'J') J = { i, j };
				if (c == 'R') R = { i, j };
			}
		}

	bfs();
	output();

	return 0;
}
    