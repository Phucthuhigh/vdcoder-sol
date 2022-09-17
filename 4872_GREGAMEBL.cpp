// GREGAMEBL

#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100005], b[100005];
long long sa, sb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a, a + n, greater<int>());
	sort(b, b + n, greater<int>());

	for (int i = 0, j = 0; i < n || j < n;)
	{
		if ((i < n && a[i] >= b[j]) || j == n)
			sa += a[i++];
		else ++j;

		if ((j < n && b[j] >= a[i]) || i == n)
			sb += b[j++];
		else ++i;
	}

	cout << sa - sb;

	return 0;
}
    