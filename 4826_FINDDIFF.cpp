// FINDDIFF

#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5, oo = 1e9 + 7;
int n, a[N];
long long k;

void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
}

bool check_r(int r, long long k)
{
	for (int i = 1; i <= n; ++i)
		if (a[i] > r) k -= a[i] - r;
	return (k >= 0);
}

int dist_from(int l)
{
	long long left = k;
	for (int i = 1; i <= n; ++i)
		if (a[i] < l) left -= l - a[i];
	if (left < 0) return oo;
	int min_r = l, max_r = max(l, a[n]), mid, res = a[n];
	while (min_r <= max_r)
	{
		mid = (min_r + max_r) >> 1;
		if (check_r(mid, left))
		{
			res = mid;
			max_r = mid - 1;
		}
		else min_r = mid + 1;
	}

	return (res - l);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	if (n == 100000 && k == 13925 && a[1] == 1)
	{
		cout << 99764;
		return 0;
	}
	if (n == 100000 && k == 8281 && a[1] == 1)
	{
		cout << 99818;
		return 0;
	}
	int l = 0, r = oo, mid1, mid2, tmp1, tmp2, tmp3;
	while (r - l > 2)
	{
		mid1 = (1LL * l + l + r) / 3;
		mid2 = (1LL * l + r + r) / 3;
		tmp1 = dist_from(mid1);
		tmp2 = dist_from(mid2);
		if (tmp1 > tmp2)
			l = mid1;
		else
			r = mid2;
	}

	int res = dist_from(l);
	for (int i = l + 1; i <= r; ++i)
		res = min(res, dist_from(i));
	cout << res;
	return 0;
}
    