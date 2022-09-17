// FINDSUBSEG

#include <iostream>
using namespace std;
long n;
long long k, a[100001];
long bit1(long k)
{
	long d = 0;
	while (k > 0)
	{
		d += (k % 2);
		k /= 2;
	}
	return d;
}
long binsearch(long long k)
{
	long l = 0, r = n - 1, mid, res = n;
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
	long k;
	cin >> n >> k;
	++n;
	for (long i = 1, tmp; i < n; ++i)
	{
		cin >> tmp;
		a[i] = a[i - 1] + bit1(tmp);
	}
	
	if (a[n - 1] < k) { cout << -1; return 0; }
	
	long lenmin = n + 1;
	for (long i = 0, t, len; i < n; ++i)
	{
		t = binsearch(a[i] + k);
		if (t == n) break;
		else
		{
			len = t - i;
			if (lenmin > len) lenmin = len;
		}
	}
	
	cout << lenmin;
}
    