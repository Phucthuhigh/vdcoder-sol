// DPRCMA

#include<iostream>
#include<algorithm>

using namespace std;

int n, a[2001], s[2001], f[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[i][i] = a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1, k = i; k <= n; ++j, ++k)
		{
			int x = f[j][j] + f[j + 1][k] + (s[k] - s[j]), y = f[k][k] + f[j][k - 1] + (s[k - 1] - s[j - 1]);
			f[j][k] = max(x, y);
		}
	}

	cout << f[1][n];
}
    