// GREMOVIES

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, k, d[100005], a[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> k >> a[1];
	for (int i = 2; i <= n;)
	{
		cin >> a[i];
		if (a[i] != a[i - 1]) ++i;
		else --n;
	}

	++d[a[1]], ++d[a[n]];
	for (int i = 2; i < n; ++i)
	{
		if (a[i - 1] == a[i + 1]) d[a[i]] += 2;
		else ++d[a[i]];
	}

	int res = 0;
	for (int i = 1; i <= k; ++i)
	{
		if (d[res] < d[i]) res = i;
	}

	cout << res;

	return 0;
}
    