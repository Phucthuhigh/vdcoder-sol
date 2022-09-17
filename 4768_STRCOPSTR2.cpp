// STRCOPSTR2

#include <iostream>
#include <string>
using namespace std;
int n, z[2000006];
string s;

void zfunc()
{
	z[0] = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i > r)
		{
			l = r = i;
			while (r < n && s[r] == s[r - l]) ++r; --r;
			z[i] = r - l + 1;
		}
		else
		{
			if (i + z[i - l] - 1 < r) z[i] = z[i - l];
			else
			{
				l = i;
				while (r < n && s[r] == s[r - l]) ++r; --r;
				z[i] = r - l + 1;
			}
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> s;
    zfunc();
    int res = n;
	for (int i = 1; i < n; ++i)
		if (z[i] >= i) res = n - i + 1;
	cout << res;
    return 0;
}
    