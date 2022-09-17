// DPKNSKC1

#include <iostream>
using namespace std;
long long f[20001];
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	long m, n;
	cin >> m >> n;
	for (long i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		for (long j = b; j <= n; ++j)
		{
			f[j] = max(f[j], f[j - b] + a);
		}
	}
	long long maxx = f[0];
	for (long i = 1; i <= n; ++i) maxx = max(maxx, f[i]);
	cout << maxx;
	return 0;
}
    