// GREUSB

#include <iostream>
#include <algorithm>
using namespace std;
long a[1000], n, m;
int main()
{
	cin >> n >> m;
	for (long i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, [](long x, long y) {return x > y; });
	long sum = 0, d = 0;
	while (sum < m) sum += a[d++];
	cout << d;
	return 0;
}
    