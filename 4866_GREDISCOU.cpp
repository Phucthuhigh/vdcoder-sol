// GREDISCOU

#include <iostream>
#include <algorithm>
using namespace std;
struct price
{
	long d,s, distance;
} a[200000];
int main()
{
	long n, k;
	cin >> n >> k;

	for (long i = 0; i < n; ++i) cin >> a[i].d;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i].s;
		a[i].distance = a[i].d - a[i].s;
	}

	sort(a, a + n, [](const price &x, const price &y) {	return (x.distance < y.distance);	});

	long long sum = 0;
	long i = 0;
	for (; (i < k || a[i].distance < 0) && i < n; ++i) sum += a[i].d;
	for (; i < n; ++i) sum += a[i].s;

	cout << sum;
	return 0;
}
    