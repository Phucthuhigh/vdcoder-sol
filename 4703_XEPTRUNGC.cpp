// XEPTRUNGC

#include <iostream>
using namespace std;
long long a[1000007];
long n, m;
long binsearch(long long k)
{
	long l = 1, r = n, mid, res = n + 1;
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
bool check(long long k)
{
	long tmp = m, i = 0;
	while (tmp--)
	{
		i = binsearch(a[i] + k);
	}
	if (i == n) return true;
	else return false;
}
long long bsearch1(long long l)
{
	long long r = a[n], mid, res = l;
	while (l <= r)
	{
		mid = (l + r) / 2;
		bool tmp = check(mid);
		if (tmp)
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
	long maxa = 0;
	cin >> n >> m;
	for (long i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (maxa < a[i]) maxa = a[i];
		a[i] += a[i - 1];
	}
	
	long long i = maxa;
	if (m < n) i = bsearch1(i);
	
	cout << i;
	return 0;
}
    