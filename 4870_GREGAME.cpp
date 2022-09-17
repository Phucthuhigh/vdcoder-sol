// GREGAME

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, a[2];
bool flag;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int t;
	cin >> t;
	while (t--)
	{
		flag = true;
		cin >> n >> m >> k;
		cin >> a[0];
		for (int i = 1; i < n; ++i)
		{
			cin >> a[1];
			if (a[0] + m < a[1] - k) flag = false;
			if (a[0] < a[1] - k)
			{
				m -= a[1] - k - a[0];
			}
			else
			{
				m += a[0] - max(a[1] - k, 0);
			}
			a[0] = a[1];
		}

		cout << (flag ? "YES\n" : "NO\n");
	}
	
	return 0;
}
    