// GREEXP

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n, k;
	long long sum;
	cin >> n >> k >> sum;
	for (long i = 1; i < n; ++i) cin >> a[i];

	sort(a + 1, a + n, greater<long>());

	long i = 1;
	for (; i <= k && i < n; ++i) sum += a[i];
	for (; i < n; ++i) sum -= a[i];
	cout << sum;
	return 0;
}
    