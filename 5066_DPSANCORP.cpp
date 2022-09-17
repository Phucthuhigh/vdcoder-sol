// DPSANCORP

#include <iostream>
#include <algorithm>
using namespace std;
struct order
{
	long long s, e, v;
} a[5001];
long long f[5001];
long long max(long long x, long long y) { if (x > y) return x; return y; }
int main()
{
	long t;
	cin >> t;
	while (t--)
	{
		long n;
		cin >> n;
		for (long i = 1; i <= n; ++i)
		{
			cin >> a[i].s >> a[i].e >> a[i].v;
			a[i].e += a[i].s - 1;
		}
		sort(a + 1, a + n + 1,
			[](const order& x, const order& y) {return (x.s < y.s); });
		for (long i = 1; i <= n; ++i)
		{
			long long maxx = 0;
			for (long j = 1; j < i; ++j)
			{
				if (a[j].e < a[i].s) maxx = max(maxx, f[j]);
			}
			f[i] = maxx + a[i].v;
		}
		long long maxx = f[1];
		for (long i = 2; i <= n; ++i) maxx = max(maxx, f[i]);
		cout << maxx << '\n';
	}
	return 0;
}
    