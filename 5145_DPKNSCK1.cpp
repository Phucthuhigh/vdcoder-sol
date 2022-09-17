// DPKNSCK1

#include <iostream>
using namespace std;
long f[1001], tmp[1001], n, m;
long max(long x, long y) { if (x > y) return x; return y; }
void copy()
{
	for (long i = 0; i <= n; ++i) tmp[i] = f[i];
}
int main()
{
	cin >> m >> n;
	for (long i = 0, a, b; i < m; ++i)
	{
		copy();
		cin >> a >> b;
		for (long j = b; j <= n; ++j)
		{
			f[j] = max(tmp[j], tmp[j - b] + a);
		}
	}
	long maxx = f[0];
	for (long i = 1; i <= n; ++i) maxx = max(maxx, f[i]);
	cout << maxx;
	return 0;
}
    