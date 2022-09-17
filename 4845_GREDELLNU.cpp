// GREDELLNU

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n, chan = 0, le = 0;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] % 2 == 0) ++chan;
		else ++le;
	}

	sort(a, a + n);

	if (chan == le || chan == le + 1 || le == chan + 1) cout << 0;
	else
	{
		if (chan > le) { chan -= le + 1; le = 0; }
		else { le -= chan + 1; chan = 0; }

		long long sum = 0;
		long i = 0;
		while (chan > 0)
		{
			if (a[i] % 2 == 0) { sum += a[i]; --chan; }
			++i;
		}

		i = 0;
		while (le > 0)
		{
			if (a[i] % 2 == 1) { sum += a[i]; --le; }
			++i;
		}

		cout << sum;
	}
	return 0;
}
    