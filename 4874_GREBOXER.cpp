// GREBOXER

#include <iostream>
using namespace std;
long a[150002];
bool f[150002];
int main()
{
	long n;
	cin >> n;

	for (long i = 0, t; i < n; ++i)
	{
		cin >> t;
		++a[t];
	}

	long d = 0, i = 150000;
	for (long i = 150000; i > 0; --i)
	{
		if (a[i] > 0 && !f[i + 1]) 
		{
			--a[i]; 
			++d; 
//			f[i + 1] = true;
		}
		if (a[i] > 0 && !f[i])
		{
			--a[i];
			++d;
			f[i] = true;
		}
		if (a[i] > 0 && !f[i - 1])
		{
			--a[i];
			++d;
			f[i - 1] = true;
		}
	}

	if (f[0]) --d;
	cout << d;
	return 0;
}
    