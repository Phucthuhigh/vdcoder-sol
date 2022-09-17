// FINDHORSE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long n;
vector<long long> a, b;
long bsearch(long long k)
{
	long l = 0, r = n - 1, mid, res = n;
	if (b[0] >= k) return 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] >= k) r = mid - 1;
		else
		{
			l = mid + 1;
			res = mid;
		}
	}
	return res + 1;
}
int main()
{
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (long i = 0; i < n; ++i) cin >> a[i];
	for (long i = 0; i < n; ++i) cin >> b[i];
	sort(b.begin(), b.end());
	for (long i = 0; i < n; ++i)
	{
		cout << bsearch(a[i]) << ' ';
	}
}
    