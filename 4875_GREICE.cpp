// GREICE

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t[10], d[10], arr[10] = {0, 1, 2, 3, 4, 2, 6, 7, 8, 6}, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i)
	{
		++t[arr[s[i] - 48]];
	}

	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i)
	{
		++d[arr[s[i] - 48]];
	}
	int res = 100000;
	for (int i = 0; i < 10; ++i)
	{
		if (t[i] > 0)
		{
			res = min(res, d[i] / t[i]);
		}
	}

	cout << res;

	return 0;
}
    