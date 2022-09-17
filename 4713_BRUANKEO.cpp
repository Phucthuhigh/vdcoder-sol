// BRUANKEO

#include <iostream>
#include <algorithm>
using namespace std;
long a[4000];
int main()
{
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);
	
	long sum = 0;
	for (long i = 1; i < n; ++i)
	{
		if (a[i - 1] < a[i]) continue;
		else
		{
			sum += a[i - 1] - a[i] + 1;
			a[i] = a[i - 1] + 1;
		}
	}
	
	cout << sum;
	return 0;
}
    