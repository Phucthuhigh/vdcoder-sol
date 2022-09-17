// DPLIS3

#include <iostream>
#include <algorithm>


using namespace std;

const int N = 1003;
int n, fen[N][N], a[100 * N], b[100 * N], dp[100 * N];

int get(int x, int y)
{
	int res = 0;
	for (int i = x ; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j)
			res = max(res, fen[i][j]);
	return res;
}

void update(int x, int y, int val)
{
	for (int i = x; i <= 1000; i += i & -i)
		for (int j = y; j <= 1000; j += j & -j)
			fen[i][j] = max(fen[i][j], val);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int res = 0;
	for (int i = 1, dp_ij; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		a[i] += 2;
		b[i] += 2;
		dp[i] = get(a[i] - 1, b[i] - 1) + 1;
		update(a[i], b[i], dp[i]);
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}
    