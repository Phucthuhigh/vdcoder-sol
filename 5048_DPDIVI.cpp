// DPDIVI

#include <iostream>
#include <algorithm>

using namespace std;

int n, l, prf[6003], dp[6003];
int main()
{
	cin >> n >> l;
	for (int i = 1, a; i <= n; ++i)
	{
		cin >> a;
		prf[i] = prf[i - 1] + a;
		dp[i] = l;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i - 1; j >= 0 && prf[i] - prf[j] <= l; --j)
		{
			if (dp[i] > max(dp[j], l - (prf[i] - prf[j])))
				dp[i] = max(dp[j], l - (prf[i] - prf[j]));
		}

	cout << dp[n];

	return 0;
}
    