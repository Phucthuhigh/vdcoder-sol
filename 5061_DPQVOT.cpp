// DPQVOT

#include <iostream>
using namespace std;
long long a[100], b[100], f[100];
int main()
{
	long n, k;
	cin >> n >> k;
	for (long i = 0; i < n; ++i) cin >> a[i];
	for (long i = 0; i < n; ++i) cin >> b[i];
	for (long i = 0; i < n; ++i) f[i] = b[i];
	for (long i = 1; i < n; ++i)
		for (long j = 0; j < i; ++j)
			if (a[i] - a[j] >= k && f[i] < f[j] + b[i]) f[i] = f[j] + b[i];
	long long maxx = f[0];
	for (long i = 1; i < n; ++i) if (maxx < f[i]) maxx = f[i];
	cout << maxx;
	return 0;
}
    