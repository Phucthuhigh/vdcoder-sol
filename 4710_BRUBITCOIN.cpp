// BRUBITCOIN

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2006;
int n, k, d[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> d[i];

	int res = 0;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			res = max(res, (d[j] - d[i]) - k * (i - j));
	cout << res;

	return 0;
}
    