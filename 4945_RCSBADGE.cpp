// RCSBADGE

#include <iostream>
#include <vector>

using namespace std;

int n, p[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];

	for (int x = 1; x <= n; ++x)
	{
		vector<bool> f(n + 1, true);
		int y = x;
		while (f[y])
		{
			f[y] = false;
			y = p[y];
		}
		cout << y << ' ';
	}

	return 0;
}
    