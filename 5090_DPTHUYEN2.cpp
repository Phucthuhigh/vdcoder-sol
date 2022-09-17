// DPTHUYEN2

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[100001], f[100001];
pair<int, int> xy[100001];
vector<int> dp;

void input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> xy[i].first >> xy[i].second;
	}
	sort(xy, xy + n);
	for (int i = 0; i < n; ++i) a[i] = xy[i].second;
}

int binsearch(int k)
{
	int l = 0, r = dp.size() - 1, mid, res = -1, flag = -10;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (dp[mid] == k)
		{
			flag = mid;
			l = mid + 1;
			continue;
		}

		if (dp[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (flag == -10) return res;
	else return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	input();
	
	for (int i = 0; i < n; ++i)
	{
		int vt = binsearch(a[i]) + 1;
		if (vt == dp.size()) dp.push_back(a[i]);
		else dp[vt] = a[i];
		f[i] = vt + 1;
	}

	int res = 0;
	for (int i = 0; i < n; ++i) if (res < f[i]) res = f[i];

	cout << n - res;

	return 0;
}
    