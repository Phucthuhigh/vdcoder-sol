// GRETEAM

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000], n;
int main()
{
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	long sum = 0;
	for (long i = 1; i <= n; i += 2) sum += a[i] - a[i - 1];
	cout << sum;
	return 0;
}
    