// FINDVUDE

#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5, oo = 1e9 + 7;
int t, n, m, a[N], b[N];

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
}

long long cal_a(int x)
{ // a[i] >= x
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += max(0, x - a[i]);
	return sum;
}

long long cal_b(int x)
{ // b[i] <= x
	long long sum = 0;
	for (int i = 1; i <= m; ++i)
		sum += max(0, b[i] - x);
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	int l = 0, r = oo, mid1, mid2;
	long long tmp1, tmp2, tmp3;
	while (r - l > 2)
	{
		mid1 = (1LL * l + l + r) / 3;
		mid2 = (1LL * l + r + r) / 3;
		tmp1 = cal_a(mid1) + cal_b(mid1);
		tmp2 = cal_a(mid2) + cal_b(mid2);
		if (tmp1 > tmp2)
			l = mid1;
		else
			r = mid2;
	}
	tmp1 = cal_a(l) + cal_b(l);
	tmp2 = cal_a(l + 1) + cal_b(l + 1);
	tmp3 = cal_a(l + 2) + cal_b(l + 2);
	cout << min(tmp1, min(tmp2, tmp3));
	return 0;
}
    