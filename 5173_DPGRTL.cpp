// DPGRTL

#include <iostream>
#include <vector>
using namespace std;
vector< vector<long long> > f, a;
long m, n, x, y;
long long max(long long a, long long b)
{
	if (a > b) return a;
	return b;
}
void set_f()
{
	f[x][y] = a[x][y];
	for (long i = x + 1; i < m; ++i) 
	{
		f[i][y] = f[i - 1][y] - a[i][y];
	}
	for (long j = y + 1; j < n; ++j) 
	{
		f[x][j] = f[x][j - 1] - a[x][j];
	}
	for (long i = x + 1; i < m; ++i)
	{
		for (long j = y + 1; j < n; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) - a[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> x >> y;
	--x;
	--y;
	f.resize(m);
	a.resize(m);
	for (long i = 0; i < m; ++i)
	{
		f[i].resize(n);
		a[i].resize(n);
		for (long j = 0; j < n; ++j) 
		{
			f[i][j] = 0;
			cin >> a[i][j];
		}
	}
	set_f();
	if (f[m - 1][n - 1] < 0) cout << 'N';
	else cout << "Y " << f[m - 1][n - 1];
	return 0;
}
    