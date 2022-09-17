// GRECHAIN

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);

	long matxich = 0, i = 0;
	while (matxich < n - 1)
	{
		if (matxich + a[i] < n - 1)
		{
			matxich += a[i];
			--n;
		}
		else
		{
			if (matxich + a[i] == n - 1)
			{
				matxich += a[i];
				--n;
			}
			else matxich = n - 1;
		}
		++i;
	}

	cout << matxich;
	return 0;
}
    