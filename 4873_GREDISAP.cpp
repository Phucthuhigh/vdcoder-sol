// GREDISAP

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000], n;
long binsearch(long l, long k)
{
	long r = n - 1, mid, res = n;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == k) return mid;
		if (a[mid] > k)
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);
	
	long d = 0, sum = 0, i = -1, t;
	while (true)
	{
		t = binsearch(i + 1, sum);
		if (t == n) break;
		else
		{
			sum += a[t];
			i = t;
			++d;
		}
	}
	
	cout << d;
}
    