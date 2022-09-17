// GRENOTSQU

#include <iostream>
#include <algorithm>

using namespace std;

int n, ye[200000], no[200000], n_y, n_n, tmp;

bool cp(int k)
{
	return (sqrt(k) == (int)sqrt(k));
}

void input()
{
	cin >> n;
	int t = n;
	while (t--)
	{
		cin >> tmp;
		if (cp(tmp))
		{
			ye[n_y++] = tmp;
		}
		else
		{
			int k = sqrt(tmp);
			no[n_n++] = min(tmp - k * k, (k + 1) * (k + 1) - tmp);
		}
	}
	n >>= 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	input();

	long long res = 0;

	if (n_n > n_y)
	{
		sort(no, no + n_n);
		for (int i = 0; n_n - i > n; ++i)
			res += no[i];
	}
	
	if (n_y > n_n)
	{
		sort(ye, ye + n_y, greater<int>());
		for (int i = 0; n_y - i > n; ++i)
			res += (ye[i] == 0 ? 2 : 1);
	}

	cout << res;
	return 0;
}
    