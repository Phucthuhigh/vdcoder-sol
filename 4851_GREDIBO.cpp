// GREDIBO

#include <iostream>
using namespace std;
long a[36000];

int main()
{
	long n, k;
	long long sum = 0;
	cin >> n >> k >> a[0];
	for (long i = 1; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] + a[i - 1] < k)
		{
			sum += k - a[i] - a[i - 1];
			a[i] = k - a[i - 1];
		}
	}

	cout << sum << '\n';
	for (long i = 0; i < n; ++i) cout << a[i] << ' ';
	return 0;
}
    