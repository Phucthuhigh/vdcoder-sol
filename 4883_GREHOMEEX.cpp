// GREHOMEEX

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, d[10];
string s[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		++d[x];
		s[x % 3].push_back(char(x + 48));
	}

	sort(s[0].begin(), s[0].end(), greater<char>());
	sort(s[1].begin(), s[1].end(), greater<char>());
	sort(s[2].begin(), s[2].end(), greater<char>());
	int dem[3] = { s[0].size(), s[1].size(), s[2].size() };
	if (d[0] == 0) cout << -1;
	else
	{
		if ((dem[1] < 3 && dem[2] == 0) || (dem[2] < 3 && dem[1] == 0))
		{
			if (d[0] == dem[0]) cout << 0;
			else cout << s[0];
		}
		else
		{
			int t = dem[1] + dem[2] * 2;
			if (t % 3 == 1)
			{
				if (dem[1] > 0)
				{
					s[1].pop_back();
					--dem[1];
				}
				else
				{
					s[2].pop_back(), s[2].pop_back();
					dem[2] -= 2;
				}
			}
			if (t % 3 == 2)
			{
				if (dem[2] > 0)
				{
					s[2].pop_back();
					--dem[2];
				}
				else
				{
					s[1].pop_back(), s[1].pop_back();
					dem[1] -= 2;
				}
			}
			int x = 0, y = 0, z = 0;
			while (x < dem[0] && s[0][x] == '9') cout << s[0][x++];
			while (z < dem[2] && s[2][z] == '8') cout << s[2][z++];
			while (y < dem[1] && s[1][y] == '7') cout << s[1][y++];
			while (x < dem[0] && s[0][x] == '6') cout << s[0][x++];
			while (z < dem[2] && s[2][z] == '5') cout << s[2][z++];
			while (y < dem[1] && s[1][y] == '4') cout << s[1][y++];
			while (x < dem[0] && s[0][x] == '3') cout << s[0][x++];
			while (z < dem[2] && s[2][z] == '2') cout << s[2][z++];
			while (y < dem[1] && s[1][y] == '1') cout << s[1][y++];
			while (x < dem[0] && s[0][x] == '0') cout << s[0][x++];
		}
	}

	return 0;
}
    