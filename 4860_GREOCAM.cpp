// GREOCAM

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, m, a[502];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> k >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, greater<int>());

	int cnt = 0, i = 0;
	while (i < n && m < k)
	{
		++cnt;
		m += a[i++] - 1;
	}

	cout << (m < k ? -1 : cnt);

	return 0;
}
    