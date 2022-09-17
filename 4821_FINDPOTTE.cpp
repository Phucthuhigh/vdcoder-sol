// FINDPOTTE

#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5, oo = 1e9 + 7;
int t, n, m, a[N], b[N];

void input()
{
	cin >> t >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i) cin >> b[i];
}

long long cntPaint(int t)
{
	long long sum = 0;
	for (int i = 1; i <= m; ++i)
		sum += t / b[i];
	return sum;
}

long long cntShape(int t)
{
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += t / a[i];
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	int l = 1, r = t, mid1, mid2;
	long long tmp1, tmp2, tmp3;
	while (r - l > 2) // 1 2 3
	{
		mid1 = (l + l + r) / 3;
		mid2 = (l + r + r) / 3;
		tmp1 = min(cntShape(mid1), cntPaint(t - mid1));
		tmp2 = min(cntShape(mid2), cntPaint(t - mid2));
		if (tmp1 < tmp2)
			l = mid1;
		else
			r = mid2;
	}
	tmp1 = min(cntShape(l), cntPaint(t - l));
	tmp2 = min(cntShape(l + 1), cntPaint(t - l - 1));
	tmp3 = min(cntShape(r), cntPaint(t - r));
	cout << max(max(tmp1, tmp2), tmp3);
	return 0;
}
    