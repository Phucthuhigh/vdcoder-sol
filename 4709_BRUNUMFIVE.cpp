// BRUNUMFIVE

#include <iostream>
using namespace std;
int main()
{
	long n, dem0 = 0, dem5 = 0, tmp;
	cin >> n;
	while (n--)
	{
		cin >> tmp;
		if (tmp) ++dem5;
		else ++dem0;
	}
	if (dem0 == 0) cout << -1;
	else
	{
		if (dem5 / 9 == 0) cout << 0;
		else
		{
			for (long i = 0; i < dem5 / 9 * 9; ++i) cout << 5;
			for (long i = 0; i < dem0; ++i) cout << 0;
		}
	}
	return 0;
}
    