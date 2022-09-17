// DPBORE

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define max(a, b) (a > b ? a : b)

int n;
long long f[100002], b[100002];

int main()
{
	cin >> n;
	for (int i = 0, a; i < n; ++i)
	{
		cin >> a;
		b[a] += a;
	}

	f[0] = b[0];
	f[1] = b[1];
	for (int i = 2; i <= 100001; ++i)
		f[i] = max(f[i - 1], f[i - 2] + b[i]);

	cout << f[100001];

	return 0;
}
    