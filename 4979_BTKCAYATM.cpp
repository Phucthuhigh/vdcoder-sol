// BTKCAYATM

#include <iostream>
#include <cmath>

using namespace std;

long long n, m, t[22], res[22];

long long tong(long k)
{
	long long sum = 0, i = 0;
	while (k > 0)
	{
		if (k % 2 == 1) sum += t[i];
		k /= 2;
		++i;
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> t[i];
	
	for (long i = 0, maxx = pow(2, n); i < maxx; ++i)
	{
		if (tong(i) == m)
		{
			int cnt = 0, k = i, j = 0;
			while (k > 0)
			{
				if (k % 2 == 1) res[cnt++] = j;
				k /= 2;
				++j;
			}
			cout << cnt << '\n';
			for (int i = 0; i < cnt; ++i) cout << res[i] + 1 << ' ';
			return 0;
		}
	}
	cout << "khongtherut";
	return 0;
}
    