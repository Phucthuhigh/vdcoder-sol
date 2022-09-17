// GRECONTE

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

	long d = 0;
	for (long i = 0; i < n; ++i)
	{
		while (i < n && a[i] <= d) ++i;
		if (i < n) ++d;
	}

	cout << d;
	return 0;
}
    