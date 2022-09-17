// CATDAY

#include <iostream>
using namespace std;
long a[100000], n, maxx;
long long sum;
long long catday(long k)
{
	long long res = 0;
	for (long i = 0; i < n; ++i) res += a[i] / k;
	return res;
}
long binsearch(long k)
{
	long l = 1, r = maxx, mid, res = maxx + 1, resk = maxx + 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		long cat = catday(mid); // cat = a[mid]
		if (cat == k)
		{
			resk = mid;
			l = mid + 1;
		}
		else
		{
			if (cat > k)
			{
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	if (resk != maxx + 1) return resk;
	return res;
}
int main()
{
	long k;
	cin >> n >> k;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
		if (maxx < a[i]) maxx = a[i];
	}

	long res = binsearch(k);
	cout << res;
	return 0;
}
    