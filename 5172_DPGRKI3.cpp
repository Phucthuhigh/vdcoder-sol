// DPGRKI3

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector< vector<long long> > f, a;
stack<long> ti, tj;
long m, n;
long long max(long long a, long long b)
{
	if (a > b) return a;
	return b;
}
void set_f()
{
	f[0][0] = a[0][0];
	for (long i = 1; i < m; ++i) f[i][0] = f[i - 1][0] + a[i][0];
	for (long j = 1; j < n; ++j) f[0][j] = f[0][j - 1] + a[0][j];
	for (long i = 1; i < m; ++i)
	{
		for (long j = 1; j < n; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
		}
	}
}
void truy_vet()
{
	long i = m - 1, j = n - 1;
	ti.push(i);
	tj.push(j);
	while (i > 0 && j > 0)
	{
		if (f[i][j] - a[i][j] == f[i - 1][j])
		{
			ti.push(--i);
			tj.push(j);
		}
		else
		{
			ti.push(i);
			tj.push(--j);
		}
	}
	while (i > 0)
	{
		ti.push(--i);
		tj.push(j);
	}
	while (j > 0)
	{
		ti.push(i);
		tj.push(--j);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
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
	cout << f[m - 1][n - 1] << '\n';
	truy_vet();
	cout << ti.size() << '\n';
	while (!ti.empty())
	{
		cout << ti.top() + 1 << ' ' << tj.top() + 1 << '\n';
		ti.pop();
		tj.pop();
	}
	return 0;
}
    