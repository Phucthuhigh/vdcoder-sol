// GRETHICO

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	long n = 0;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);

	long l = 0, r = 1, maxlen = 1;
	for ( ; r < n; ++r)
	{
		if (a[r] > 2 * a[l])
		{
			maxlen = max(maxlen, r - l);
			while (a[r] >= 2 * a[l]) ++l;
		}
	}

	maxlen = max(maxlen, r - l);

	cout << maxlen;

	return 0;
}
    