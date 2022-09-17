// DPSEG

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
long long f[1000];
pair <long long, long long> a[1000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i) { cin >> a[i].first >> a[i].second; f[i] = 1; }
	sort(a, a + n, 
		[](const pair<long long, long long>& x, const pair<long long, long long>& y) 
		{
			return (x.first < y.first || (x.first == y.first && x.second >= y.second));
		} );
	for (long i = n - 1; i >= 0; --i)
		for (long j = n - 1; j > i; --j)
			if (a[i].second >= a[j].second && f[i] < f[j] + 1) f[i] = f[j] + 1;
	long maxx = f[0];
	for (long i = 1; i < n; ++i) if (maxx < f[i]) maxx = f[i];
	cout << maxx;
	return 0;
}
    