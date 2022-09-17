// GREMEDIAN

#include <iostream>
#include <algorithm>

using namespace std;

int n, x, a[502];
bool checkx = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] == x) checkx = true;
	}
	if (!checkx)
	{
		++n;
		a[n] = x;
	}
	sort(a + 1, a + n + 1);

	int low = lower_bound(a + 1, a + n + 1, x) - a;
	int upp = upper_bound(a + 1, a + n + 1, x) - a - 1;
	int mid = (n + 1) >> 1;

	int res = 5000;
	if (low <= mid && upp >= mid) res = 0;
	else
	{
		if (mid > upp)
		{
			if (n & 1)
				res = min(res, (mid - upp - 1) * 2 + 1);
			else
				res = min(res, (mid - upp) * 2);
		}
		else
		{
			if (n & 1)
				res = min(res, (low - mid) * 2);
			else
				res = min(res, (low - mid - 1) * 2 + 1);
		}
	}
	
	cout << res + (checkx ? 0 : 1);

	return 0;
}
    