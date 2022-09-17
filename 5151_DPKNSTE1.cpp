// DPKNSTE1

#include <iostream>
#include <algorithm>

using namespace std;

int n, wmax, w, v;
long long f[100001];

int main()
{
	f[0] = 0;
	for (int i = 1; i <= 100000; ++i) f[i] = 1000000000000000;

	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> wmax;

	while (n--)
	{
		cin >> w >> v;
		for (int i = 100000; i >= v; --i)
		{
			f[i] = min(f[i], f[i - v] + w);
		}
	}

	long long res = 0;
	for (int i = 0; i <= 100000; ++i)
	{
		if (f[i] <= wmax) res = i;
	}

	cout << res;

	return 0;
}
    