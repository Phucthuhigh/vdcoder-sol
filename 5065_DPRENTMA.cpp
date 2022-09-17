// DPRENTMA

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
long long f[5001];
pair<long long, long long> a[5001];
long long max(long long x, long long y) { if (x > y) return x; return y; }
int main()
{
	long n;
	cin >> n;
	for (long i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for (long i = 1; i <= n; ++i)
	{
		long long maxx = 0;
		for (long j = 1; j < i; ++j)
		{
			if (a[j].second < a[i].first) maxx = max(maxx, f[j]);
		}
		f[i] = maxx + a[i].second - a[i].first + 1;
	}
	long long maxx = f[1];
	for (long i = 2; i <= n; ++i) maxx = max(maxx, f[i]);
	cout << maxx;
	return 0;
}
    