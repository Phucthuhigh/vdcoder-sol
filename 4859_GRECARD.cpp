// GRECARD

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];
int main()
{
	long n, cnt = 0, ta, tb;
	long long sumb = 1, sum = 0;
	cin >> n;
	
	while (n--)
	{
		cin >> ta >> tb;
		if (tb == 0) a[cnt++] = ta;
		else
		{
			sumb += tb - 1;
			sum += ta;
		}
	}

	sort(a, a + cnt, greater<long>());

	if (cnt > sumb) cnt = sumb;
	for (long i = 0; i < cnt; ++i) sum += a[i];

	cout << sum;

	return 0;
}
    