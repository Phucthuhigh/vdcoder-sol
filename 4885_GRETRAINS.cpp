// GRETRAINS

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
pair<int, int> a[100005];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);

	int res = 1;
	for (int i = 1, s = 1; i < n; ++i)
	{
		if (a[i].second > a[i - 1].second) ++s;
		else s = 1;

		if (res < s) res = s;
	}

	cout << n - res;

	return 0;
}
    