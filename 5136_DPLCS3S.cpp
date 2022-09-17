// DPLCS3S

#include <iostream>
#include <string>
using namespace std;
int n, m, k, arr[101][101][101];
string a, b, c;
int max(const int& a, const int& b, const int& c)
{
	int res = a;
	if (res < b) res = b;
	if (res < c) res = c;
	return res;
}
int lcs()
{
	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int z = 1; z <= k; ++z)
			{
				if (a[i] == b[j] && a[i] == c[z]) arr[i][j][z] = arr[i - 1][j - 1][z - 1] + 1;
				else arr[i][j][z] = max(arr[i - 1][j][z], arr[i][j - 1][z], arr[i][j][z - 1]);
			}
		}
	}
	return arr[n][m][k];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> a >> b >> c;
		cout << lcs() << '\n';
	}
	return 0;
}
    