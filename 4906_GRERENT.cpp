// GRERENT

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
	for (int i = 0, t, d; i < n; ++i)
	{
		cin >> t;
		a[i] = { t, 1 };
	}
	for (int i = 0, d; i < n; ++i)
	{
		cin >> d;
		a[i + n] = { a[i].first + d, -1 };
	}
	
	n <<= 1;
	sort(a, a + n);
	for (int i = 0, sum = 0; i < n; ++i)
	{
		sum += a[i].second;
		res = max(res, sum);
	}

	cout << res;

	return 0;
}
    