// DPRENTHT

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
long long b[5001], maxa = 1000000007;
pair<long long, long long> a[5001];
long n, cnt;
long binsearch(long long k)
{
	long l = 1, r = cnt, mid, res = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] == k) return mid - 1;
		if (b[mid] < k)
		{
			l = mid + 1;
			res = mid;
		}
		else r = mid - 1;
	}
	return res;
}
int main()
{
	cin >> n;
	for (long i = 1; i <= n; ++i)
	{
		cin >> a[i].first >> a[i].second;
		b[i] = maxa;
	}
	sort(a + 1, a + n + 1);
	b[0] = -maxa;
	cnt = 0;
	for (long i = 1, k; i <= n; ++i)
	{
		k = binsearch(a[i].first);
		if (k == cnt) b[++cnt] = a[i].second;
		else
		{
			if (a[i].second < b[k + 1]) b[k + 1] = a[i].second;
		}
	}
	cout << cnt;
	return 0;
}
    