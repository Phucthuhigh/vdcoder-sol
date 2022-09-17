// DPKNSUB1

#include <iostream>
using namespace std;
bool max(bool x, bool y) { return (x || y); }
int main()
{
	ios_base::sync_with_stdio(false);
	long t, a[101];
	bool f[101][50001];
	cin >> t;
	for (long u = 0, n; u < t; ++u)
	{
		cin >> n;
		long  sum = 0;
		for (long i = 1; i <= n; ++i) { cin >> a[i]; sum += a[i]; }
		if (sum % 2 == 1) cout << "NO\n";
		else
		{
			f[0][0] = true;
			for (long j = 1; j <= sum / 2; ++j) f[0][j] = false;
			for (long i = 1; i <= n; ++i)
			{
				for (long j = 0; j < a[i] && j <= sum / 2; ++j) f[i][j] = f[i - 1][j];
				for (long j = a[i]; j <= sum / 2; ++j) f[i][j] = max(f[i - 1][j - a[i]], f[i - 1][j]);
			}
			if (f[n][sum / 2]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
    