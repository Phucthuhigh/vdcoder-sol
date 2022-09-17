// BTKQUEEN1

#include <iostream>
#include <algorithm>

using namespace std;

int x, y;
bool row[8], col[8], cro1[15], cro2[15];
/*
	cro1 is main cross: x - y = const
	cro2 is sub cross: x + y = const
*/

bool BT(int i)
{
	if (i == 9) return true;
	if (row[i] == true)
	{
		if (BT(i + 1)) return true;
	}
	else
	{
		for (int j = 0; j < 8; ++j)
		{
			if (!row[i] && !col[j] && !cro1[i - j + 7] && !cro2[i + j])
			{
				row[i] = col[j] = cro1[i - j + 7] = cro2[i + j] = true;
				if (BT(i + 1))
				{
					cout << i + 1 << ' ' << j + 1 << '\n';
					return true;
				}
				row[i] = col[j] = cro1[i - j + 7] = cro2[i + j] = false;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> x >> y;
	row[--x] = col[--y] = cro1[x - y + 7] = cro2[x + y] = true;

	BT(0);

	return 0;
}
    