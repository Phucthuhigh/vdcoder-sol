// DPSMAX

#include <iostream>
using namespace std;
long long a[5000], b[5000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	for (long i = 1; i < n; ++i)
		for (long j = 0; j < i; ++j)
			if (a[i] >= a[j] && b[i] < b[j] + a[i]) b[i] = b[j] + a[i];
	long long maxx = b[0];
	for (long i = 1; i < n; ++i) if (maxx < b[i]) maxx = b[i];
	cout << maxx;
	return 0;
}
    