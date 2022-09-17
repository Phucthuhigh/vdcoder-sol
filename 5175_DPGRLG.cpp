// DPGRLG

#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long t;
	cin >> t;
	for (long u = 0; u < t; ++u)
	{
		long m, n;
		cin >> m >> n;
		long hang[m], cot[n];
		for (long tmp = 0; tmp < m; ++tmp) hang[tmp] = -1;
		for (long tmp = 0; tmp < n; ++tmp) cot[tmp] = -1;
		for (long i = 0; i < m; ++i)
		{
			char c;
			for (long j = 0; j < n; ++j)
			{
				cin >> c;
				if (c == 'C') 
				{
					hang[i] = j;
					cot[j] = i;
				}
			}
		}
		long d = 0;
		for (long j = 0; j < n; ++j)
		{
			for (long i = cot[j] + 1; i < m; ++i)
			{
				if (hang[i] < j) ++d;
			}
		}
		cout << d << '\n';
	}
	return 0;
}
    