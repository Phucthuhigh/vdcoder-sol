// DPLCSPALI

#include <iostream>
#include <string>
using namespace std;
long f[2001][2001];
int main()
{
	string a, b = "";
	cin >> a;
	for (long i = 0; i < a.size(); ++i)
		b = a[i] + b;
	a = ' ' + a;
	b = ' ' + b;
	for (long i = 1; i < a.size(); ++i)
		for (long j = 1; j < b.size(); ++j)
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else
			{
				if (f[i - 1][j] > f[i][j - 1]) f[i][j] = f[i - 1][j];
				else f[i][j] = f[i][j - 1];
			}
	string kq = "";
	long i = a.size() - 1, j = b.size() - 1;
	while (i > 0 && j > 0)
	{
		if (a[i] == b[j])
		{
			kq = a[i] + kq;
			--i;
			--j;
		}
		else
		{
			if (f[i][j] == f[i - 1][j]) --i;
			else --j;
		}
	}
	cout << kq;
	return 0;
}
    