// DPGRTLT

#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e3 + 7;
int m, n, a[N][N], NW[N][N], NE[N][N], SW[N][N], SE[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) cin >> a[i][j];

	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			NW[i][j] = max(NW[i - 1][j], NW[i][j - 1]) + a[i][j];

	for (int i = m; i >= 1; --i)
		for (int j = 1; j <= n; ++j)
			SW[i][j] = max(SW[i + 1][j], SW[i][j - 1]) + a[i][j];

	for (int i = 1; i <= m; ++i)
		for (int j = n; j >= 1; --j)
			NE[i][j] = max(NE[i - 1][j], NE[i][j + 1]) + a[i][j];

	for (int i = m; i >= 1; --i)
		for (int j = n; j >= 1; --j)
			SE[i][j] = max(SE[i + 1][j], SE[i][j + 1]) + a[i][j];

	int res = 0;
	for (int i = 2; i < m; ++i)
		for (int j = 2; j < n; ++j)
		{
			res = max(res, NW[i - 1][j] + SW[i][j - 1] + NE[i][j + 1] + SE[i + 1][j]);
			res = max(res, NW[i][j - 1] + SW[i + 1][j] + NE[i - 1][j] + SE[i][j + 1]);
		}
	
	cout << res;
	return 0;
}
    