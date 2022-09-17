// QUADRUGCD

#include <iostream>
#include <algorithm>

using namespace std;

int l, r, k, num[5005], G[5005][5005];
long long res;

void dw()
{
	for (int i = 2; i <= 5000; ++i)
	{
		for (int j = i; j <= 5000; j += i)
			for (int k = j; k <= 5000; k += i)
				G[j][k] = G[k][j] = i;
	}

	for (int i = 1; i <= 5000; ++i)
		for (int j = i; j <= 5000; ++j)
			if (G[i][j] == 0) G[i][j] = G[j][i] = 1;
}

int main()
{
	dw();
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> l >> r >> k;

	l = (l + k - 1) / k;
	r /= k;

	for (int i = l; i <= r; ++i)
		for (int j = l; j <= r; ++j) ++num[G[i][j]];

	for (int i = 1; i <= 5000; ++i)
		for (int j = 1; j <= 5000; ++j)
			if (G[i][j] == 1) res += 1LL * num[i] * num[j];

	cout << res;

	return 0;
}
    