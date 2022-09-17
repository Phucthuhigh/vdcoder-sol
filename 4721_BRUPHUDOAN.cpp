// BRUPHUDOAN

#include <iostream>
using namespace std;
long a[1000001], maxn = 1000000;
long long max(long long x, long long y) { if (x > y) return x; return y; }
int main()
{
	ios_base::sync_with_stdio(false);
	long n;
	cin >> n;
	
	long l, r, tmp = n;
	while (tmp--)
	{
		cin >> l >> r;
		++a[l];
		--a[r + 1];
	}

	long long sum = 0, maxx = 0;
	for (long i = 1; i <= maxn; ++i)
	{
		sum += a[i];
		maxx = max(maxx, sum);
	}
	
	sum = 0;
	for (long i = 1; i <= maxn; ++i)
	{
		sum += a[i];
		if (sum == maxx) cout << i << ' ';
	}
	return 0;
}
    