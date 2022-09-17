// TRUNGTHU

#include <iostream>
#include <algorithm>
using namespace std;
long n, a[100001], x;
long binsearch(long k)
{
	long l = 0, r = n - 1, mid, res = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == k) return mid;
		if (a[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	for (long i = 0; i < n; ++i) cin >> a[i];

	sort(a, a + n);

	long maxx = 0;
	for (long i = 0, t; i < n; ++i)
	{
		t = binsearch(x - a[i]);
		if (i >= t)
		{
			if ((t > 0 && a[t] == a[t - 1]) || (t < n - 1 && a[t] == a[t + 1])) maxx = max(maxx, a[t] * 2);
			break;
		}
		maxx = max(maxx, a[i] + a[t]);
	}

	cout << maxx;
	return 0;
}
    