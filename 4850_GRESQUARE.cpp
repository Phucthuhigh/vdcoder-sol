// GRESQUARE

#include <iostream>
#include <algorithm>
using namespace std;
long a[500];

int main()
{
	long n, k;
	cin >> n >> k;
	for (long i = 0; i < n; ++i) cin >> a[i];

	sort(a, a + n, greater<long>());

	if (a[k] == a[k - 1]) cout << -1;
	else cout << a[k - 1] << ' ' << 0;
	return 0;
}
    