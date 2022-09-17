// GRETHAMAY

#include <iostream>
#include <algorithm>
using namespace std;
long a[2001];
int main()
{
	long n, k;
	cin >> n >> k;
	for (long i = 1; i <= n; ++i) cin >> a[i];

	sort(a + 1, a + n + 1);

	long sum = 0;
	for (long i = n; i >= k; i -= k) sum += a[i] * 2 - 2;
	
	if (n % k != 0) sum += a[n % k] * 2 - 2;
	
	cout << sum;
	return 0;
}
    