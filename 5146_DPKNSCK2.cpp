// DPKNSCK2

#include <iostream>
#include <stack>
using namespace std;
long f[1001][1001], a[1001], b[1001], n, m;
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	cin >> m >> n;
	for (long i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
		for (long j = 0; j < b[i] && j <= n; ++j) f[i][j] = f[i - 1][j];
		for (long j = b[i]; j <= n; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][j - b[i]] + a[i]);
		}
	}
	long i = m, j, maxx = 0;
	for (j = 1; j <= n; ++j) if (f[i][maxx] < f[i][j]) maxx = j;
	j = maxx;
	stack<long> tmp;
	while (i > 0)
	{
		if (f[i][j] != f[i - 1][j])
		{
			j -= b[i];
			tmp.push(i);
		}
		--i;
	}
	cout << tmp.size() << '\n';
	while (!tmp.empty())
	{
		cout << tmp.top() << ' ';
		tmp.pop();
	}
	return 0;
}
    