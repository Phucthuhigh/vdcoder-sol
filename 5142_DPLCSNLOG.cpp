// DPLCSNLOG

#include <iostream>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 9;
int id[N], arr[N], dp[N];
int n, m, cnt;

int binsearch(long k)
{
	int l = 0, r = cnt - 1, mid, res = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (dp[mid] == k) return mid - 1;
		if (dp[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
	for (int i = 1, a; i <= m; ++i) cin >> a, id[a] = i;
    for (int j = 1, b; j <= n; ++j) {
        cin >> b;
        if (id[b] != 0) arr[++cnt] = id[b];
    }

	n = cnt, cnt = 0;
	int res = 0;
	for (int i = 1, pos; i <= n; ++i)
	{
		pos = binsearch(arr[i]) + 1;
		if (pos == cnt) dp[cnt++] = arr[i];
		else dp[pos] = arr[i];
		res = max(res, pos + 1);
	}
	cout << res;
    return 0;
}
    