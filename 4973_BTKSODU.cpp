// BTKSODU

#include <iostream>
#include <algorithm>

using namespace std;

int a[9][9], cnt_row[9];
bool row[9][9], col[9][9], reg[3][3][9], flag = false;

void BT(int i, int j)
{
	if (flag) return;
	if (i == 9)
	{
		flag = true;
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j) cout << a[i][j] + 1 << ' ';
			cout << '\n';
		}
		return;
	}

	while (j < 9 && a[i][j] != -1) ++j;

	if (j < 9)
		for (int num = 0; num < 9; ++num)
		{
			if (!row[i][num] && !col[j][num] && !reg[i / 3][j / 3][num])
			{
				row[i][num] = true;
				col[j][num] = true;
				reg[i / 3][j / 3][num] = true;
				a[i][j] = num;
				++cnt_row[i];

				if (!flag) BT(i, j + 1);

				row[i][num] = false;
				col[j][num] = false;
				reg[i / 3][j / 3][num] = false;
				a[i][j] = -1;
				--cnt_row[i];
			}
		}
	
	if (!flag && cnt_row[i] == 9) BT(i + 1, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			cin >> a[i][j];
			--a[i][j];
			if (a[i][j] != -1)
			{
				row[i][a[i][j]] = true;
				col[j][a[i][j]] = true;
				reg[i / 3][j / 3][a[i][j]] = true;
				++cnt_row[i];
			}
		}

	BT(0, 0);
	
	return 0;
}
    