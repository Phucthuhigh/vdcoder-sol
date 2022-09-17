// GRERECOV

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
long long a[200005], l = 0, r = 1000000000000000000, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0; i < (n >> 1); ++i)
	{
		cin >> b;
		a[i] = l;
		b -= l;
		if (b > r)
		{
			a[n - i - 1] = r;
			b -= r;
			a[i] += b;
			l += b;
		}
		else
		{
			a[n - i - 1] = b;
			r = b;
		}
	}

	for (int i = 0; i < n; ++i) cout << a[i] << ' ';

	return 0;
}
    