// DPLIQ1

#include <iostream>
using namespace std;
long long b[5001], maxa = 1000000007, cntb = 0;
long binsearch(long long k)
{
	long l = 1, r = cntb, mid, res = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] == k) return mid - 1;
		if (b[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
int main()
{
	long n;
	cin >> n;
	b[0] = -maxa;
	for (long i = 1; i <= n; ++i) b[i] = maxa;
	long t;
	while (n--)
	{
		cin >> t;
		long k = binsearch(t);
		if (k == cntb) b[++cntb] = t;
		else
		{
			if (t < b[k + 1]) b[k + 1] = t;
		}
	}
	cout << cntb;
	return 0;
}
    