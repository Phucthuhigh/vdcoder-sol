// GREGIDA

#include <iostream>
#include <algorithm>
using namespace std;
long n, a[100000], b[100000];
int main()
{
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	for (long i = 0; i < n; ++i) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n);
	
	long i = 0, j = 0, d = 0;
	while (i < n)
	{
		while (i < n && b[i] <= a[j]) ++i;
		if (i < n) ++d;
		++i;
		++j;
	}
	cout << d;
}
    