// DPLIS1

#include <iostream>
#include <vector>

using namespace std;
vector<long> dp;

int binsearch(long k)
{
	int l = 0, r = dp.size() - 1, mid, res = -1;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int> f(n);
	for (int i = 0; i < n; ++i)
	{
		int vt = binsearch(a[i]) + 1;
		if (vt == dp.size()) dp.push_back(a[i]);
		else dp[vt] = a[i];
		f[i] = vt + 1;
	}

	int res = 0;
	for (int i = 0; i < n; ++i) if (res < f[i]) res = f[i];

	cout << res;
	return 0;
}
    