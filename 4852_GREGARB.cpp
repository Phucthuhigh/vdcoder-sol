// GREGARB

#include <iostream>
using namespace std;
int main()
{
	long n, k, now = 0, pre = 0;
	long long sum = 0;
	cin >> n >> k;
	for (long i = 0; i < n; ++i)
	{
		cin >> now;
		
		if (pre > 0)
		{
			sum += pre / k;
			pre %= k;
			if (pre > 0)
			{
				++sum;
				now -= (k - pre);
				if (now < 0) now = 0;
			}
		}
		pre = now;
	}

	cout << sum + (pre + k - 1) / k;
	return 0;
}
    