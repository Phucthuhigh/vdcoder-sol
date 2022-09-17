// GREHAITV

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, res;
pair<int, int> a[400005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0, l, r; i < n; ++i)
	{
		cin >> l >> r;
		a[i << 1] = { l, 1 };
		a[i << 1 | 1] = { r + 1, -1 };
	}

	n <<= 1;
	sort(a, a + n);
	for (int i = 0, sum = 0; i < n; ++i)
	{
		sum += a[i].second;
		res = max(res, sum);
	}

	cout << (res <= 2 ? "YES" : "NO");

	return 0;
}
    