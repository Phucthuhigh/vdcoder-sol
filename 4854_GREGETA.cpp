// GREGETA

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n;
	long long sum = 0;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);

	long s = n * 45 - sum * 10, i;
	for (i = 0; i < n; ++i)
	{
		if (s <= 0) break;
		s -= (50 - a[i] * 10);
	}
	cout << i;
	return 0;
}
    