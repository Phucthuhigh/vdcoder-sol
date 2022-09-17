// GRETRIANG

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);

	for (long i = 2; i < n; ++i)
	{
		long x = a[i - 2], y = a[i - 1], z = a[i];
		if (x + y > z && y + z > x && z + x > y) { cout << "YES"; return 0; }
	}
	cout << "NO";
	return 0;
}
    