// GREFREE

#include <iostream>
#include <algorithm>
using namespace std;
long a[100001], b;
int main()
{
	long n, m;
	long long sum = 0;
	cin >> n >> m;
	for (long i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1, greater<long>());

	b = n + 1;
	for (long i = 1, tmp; i <= m; ++i)
	{
		cin >> tmp;
		if (b > tmp) b = tmp;
	}

	cout << sum - a[b];
	return 0;
}
    