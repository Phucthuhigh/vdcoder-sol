// FINDLOVENU

#include <iostream>
using namespace std;
long long z, a[3500001];
bool bsearch(long long k)
{
	long l = 1, r = 3500000, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == k) return true;
		else
		{
			if (a[mid] > k) r = mid - 1;
			else l = mid + 1;
		}
	}
	return false;
}
int main()
{
	cin >> z;
	a[0] = 0;
	for (long i = 1; i < 3500001; ++i) a[i] = i + a[i - 1];
	for (long i = 1; a[i] <= z / 2; ++i) 
		if (bsearch(z - a[i]))
		{
			cout << a[i] << ' ' << z - a[i];
			return 0;
		}
	cout << -1;
}
    