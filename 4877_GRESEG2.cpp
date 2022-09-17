// GRESEG2

#include <iostream>
#include <algorithm>

using namespace std;

struct seg {
	int s, d, pos;
} a[300005];

int n, l, r, res[300005], cnt;

bool operator < (const seg& x, const seg& y)
{
	return (x.s < y.s);
}

bool processing()
{
	int r1 = l, i = 0, pos;
	while (l < r)
	{
		while (i < n && a[i].s <= l)
		{
			if (r1 < a[i].d)
			{
				r1 = a[i].d;
				pos = a[i].pos;
			}
			++i;
		}

		if (l >= r1) return false;
		l = r1;
		res[cnt++] = pos;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].s >> a[i].d;
		a[i].pos = i + 1;
	}

	sort(a, a + n);

	if (processing())
	{
		cout << cnt << '\n';
		for (int i = 0; i < cnt; ++i)
		{
			cout << res[i] << ' ';
		}
	}
	else cout << -1;

	return 0;
}
    