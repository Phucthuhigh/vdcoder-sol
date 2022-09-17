// GREBITCO2

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 8;
int n;
ll k, d[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> d[i];

/*	int res = 0;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			res = max(res, (d[j] - d[i]) - k * (i - j)); // d[j] + k*j  -d[i]-k*i
*/
	ll res = 0, tmp = d[1] + k;
	for (int i = 2; i <= n; ++i) {
		res = max(res, tmp - d[i] - k * i);
		tmp = max(tmp, d[i] + k * i);
	}
	cout << res;

	return 0;
}
    