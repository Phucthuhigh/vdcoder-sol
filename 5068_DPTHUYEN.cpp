// DPTHUYEN

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<long, long> a[5000];
long f[5000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

	sort(a, a + n);

	for (long i = 0, maxx; i < n; ++i)
	{
		maxx = 0;
		for (long j = 0; j < i; ++j)
		{
			if (a[j].first <= a[i].first && a[j].second <= a[i].second && maxx < f[j]) maxx = f[j];
		}
		f[i] = maxx + 1;
	}

	long maxx = f[0];
	for (long i = 1; i < n; ++i)
	{
		if (maxx < f[i]) maxx = f[i];
	}

	cout << n - maxx;
	return 0;
}
    