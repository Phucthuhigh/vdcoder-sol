// FINDLECH

#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
long long a[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> q;
	for (int i = 1, tmp; i <= n; ++i)
	{
		cin >> tmp;
		a[i] = a[i - 1] + tmp;
	}

	int l, r;
	while (q--)
	{
		cin >> l >> r;
		long long sum = a[r] - a[l - 1];
		int bin = lower_bound(a + l, a + r + 1, (sum >> 1) + a[l - 1]) - a;
		long long x = abs((a[r] - a[bin - 1]) - (a[bin - 1] - a[l - 1])); // [l..bin-1] [bin..r]
		long long y = abs((a[r] - a[bin]) - (a[bin] - a[l - 1]));
		
		cout << min(x, y) << '\n';
	}
	
	return 0;
}
    