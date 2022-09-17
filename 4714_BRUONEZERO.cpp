// BRUONEZERO

#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;

	long long k = 1, d1 = 0;

	while ((k - 1) * 2 <= n) { k *= 2; ++d1; }

	long long k1 = (k - 1) * 2, d2 = d1 - 1, i = 1;
	while (k1 - i > n)
	{
		--d2;
		k1 -= i;
		i *= 2;
	}

	if (d2 < 0) d2 = 0;
	cout << d1 * (d1 - 1) / 2 + d2;
	return 0;
}
    