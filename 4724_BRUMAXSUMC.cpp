// BRUMAXSUMC

#include <iostream>
#include <algorithm>
using namespace std;
long a[200001], tang[200002];
int main()
{
	long n, q;
	cin >> n >> q;
	for (long i = 1; i <= n; ++i) cin >> a[i];
	
	long l, r;
	while (q--)
	{
		cin >> l >> r;
		++tang[l];
		--tang[r + 1];
	}
	
	for (long i = 1; i <= n; ++i) tang[i] += tang[i - 1];

	sort(a + 1, a + n + 1, greater<long>());
	sort(tang + 1, tang + n + 1, greater<long>());
	
	long long res = 0;
	for (long i = 1; i <= n; ++i) res += 1LL * a[i] * tang[i];
	
	cout << res;
	return 0;
}
    