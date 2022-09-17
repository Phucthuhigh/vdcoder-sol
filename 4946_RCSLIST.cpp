// RCSLIST

#include <iostream>
#include <algorithm>
#include <queue>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;
typedef long long ll;
const int N = (int)1e2 + 5;

int n;
ll p[N], a[N][4];

void _sort()
{
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i][2] > a[j][2] || (a[i][2] == a[j][2] && a[i][3] < a[j][3]))
			{
				swap(p[i], p[j]);
				swap(a[i], a[j]);
			}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		ll tmp = p[i];
		while (tmp % 2 == 0) ++a[i][2], tmp >>= 1;
		while (tmp % 3 == 0) ++a[i][3], tmp /= 3;
	}
	_sort();
	for (int i = 1; i <= n; ++i) cout << p[i] << ' ';

	return 0;
}
    