// GREGETRATE

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, res[300005];
pair<int, int> a[300005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);
	res[a[0].second] = a[0].first;
	for (int i = 1; i < n; ++i)
	{
		if (a[i].first <= a[i - 1].first) a[i].first = a[i - 1].first + 1;
		res[a[i].second] = a[i].first;
	}

	for (int i = 0; i < n; ++i) cout << res[i] << ' ';

	return 0;
}
    