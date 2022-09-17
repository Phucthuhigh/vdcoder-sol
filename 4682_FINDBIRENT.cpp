// FINDBIRENT

#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5, oo = 1e9 + 7;
int n, m, a[N], b[N];
long long k;

void input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= m; ++i) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
}

long long cal(int len)
{
	long long sum = 0;
	for (int i_b = 1, i_a = n - len + 1; i_a <= n; ++i_b, ++i_a)
		sum += max(0, b[i_b] - a[i_a]);
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	int l = 1, r = min(n, m), mid, best = 0, cost = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		long long sum = cal(mid);
		if (sum <= k)
		{
			best = mid;
			cost = sum;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << best << ' ' << cost;
	return 0;
}
    