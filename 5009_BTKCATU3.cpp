// BTKCATU3

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<long long, long long> pll;

const int N = 1 << 20;
int n, mid;
long long m, w[50], v[50], cnt1, cnt2;
pll a[N], b[N];

void build_a(long long wei, long long val, int pos, bool type)
{
	if (wei > m) return;
	if (type) a[cnt1++] = make_pair(wei, val);
	if (pos > mid) return;
	build_a(wei, val, pos + 1, false);
	build_a(wei + w[pos], val + v[pos], pos + 1, true);
}

void build_b(long long wei, long long val, int pos, bool type)
{
	if (wei > m) return;
	if (type) b[cnt2++] = make_pair(wei, val);
	if (pos > n) return;
	build_b(wei, val, pos + 1, false);
	build_b(wei + w[pos], val + v[pos], pos + 1, true);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

	mid = n >> 1;
	build_a(0, 0, 1, true);
	build_b(0, 0, mid + 1, true);

	sort(b, b + cnt2);
	// set lai b.second = max_val(b + 0, b + i + 1)
	for (int i = 1; i < cnt2; ++i)
	{
		b[i].second = max(b[i].second, b[i - 1].second);
	}

	long long res = 0;
	for (int i = 0, j; i < cnt1; ++i)
	{ // m - a[i].first + 1
		j = lower_bound(b, b + cnt2, make_pair(m - a[i].first + 1, 0LL),
			[](const pll& x, const pll& y)
			{
				return x.first < y.first;
			}) - b - 1;
		res = max(res, a[i].second + b[j].second);
	}
	cout << res;
	return 0;
}
    