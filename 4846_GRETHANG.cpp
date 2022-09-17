// GRETHANG

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
long min(long x, long y, long z)
{
	if (x > y) x = y;
	if (x > z) x = z;
	return x;
}
int main()
{
	long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (long i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, greater<long>());
		cout << min(n - 2, a[0] - 1, a[1] - 1) << '\n';
	}
	return 0;
}
    