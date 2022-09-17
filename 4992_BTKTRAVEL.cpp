// BTKTRAVEL

#include <iostream>
#include <algorithm>

using namespace std;

int n, c[20][20];
long long res = 100000000000;
bool kt[20];

void BT(long long sum, int x, int y)
{
	if (sum >= res) return;
	if (x == n)
	{
		res = sum;
		return;
	}

	for (int i = 1; i <= n; ++i)
		if (!kt[i])
		{
			kt[i] = true;
			BT(sum + c[y][i], x + 1, i);
			kt[i] = false;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c[i][j];

	BT(0, 0, 0);
	cout << res;

	return 0;
}
    