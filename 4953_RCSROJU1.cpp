// RCSROJU1

#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int n, m;
char matrix[502][502];
pair<int, int> start, endd;

void bfs()
{
	queue<pair<int, int> > q;
	q.push(start);
	while (!q.empty())
	{
		pair<int, int> x = q.front();
		int i = x.first, j = x.second;
		matrix[i][j] = 'x';
		q.pop();
		if (matrix[i - 1][j] == 'o') q.push(make_pair(i - 1, j));
		if (matrix[i + 1][j] == 'o') q.push(make_pair(i + 1, j));
		if (matrix[i][j - 1] == 'o') q.push(make_pair(i, j - 1));
		if (matrix[i][j + 1] == 'o') q.push(make_pair(i, j + 1));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 'R') start = make_pair(i, j);
			if (matrix[i][j] == 'J') endd = make_pair(i, j);

		}
	}
	for (int i = 1; i <= m; ++i) matrix[i][0] = matrix[i][n + 1] = 'x';
	for (int j = 1; j <= n; ++j) matrix[0][j] = matrix[m + 1][j] = 'x';
	matrix[endd.first][endd.second] = 'o';

	bfs();

	if (matrix[endd.first][endd.second] == 'x') cout << "YES";
	else cout << "NO";
	return 0;
}
    