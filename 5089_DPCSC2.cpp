// DPCSC2

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, a[100005], dp[51][100005];
unordered_map<int, int> mymap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		for (int d = 1; d <= 50; ++d)
		{
			if (mymap.find(a[i] - d) == mymap.end())
				dp[d][i] = 1;
			else
				dp[d][i] = dp[d][mymap[a[i] - d]] + 1;

			mymap[a[i]] = i;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int d = 1; d <= 50; ++d)
			res = max(res, dp[d][i]);

	cout << res;

	return 0;
}
    