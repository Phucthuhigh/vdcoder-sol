// GREEXAM

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, d[101], sum;

int cnt(int k)
{
	int s = sum, cnt = 0;
	for (int i = 100; s > k && i > 0; --i)
	{
		if (s - d[i] * i > k)
		{
			s -= d[i] * i;
			cnt += d[i];
		}
		else
		{
			int x = (s - k + i - 1) / i;
			s -= x * i;
			cnt += x;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> m;
	for (int i = 0, a; i < n; ++i)
	{
		cin >> a;
		cout << cnt(m - a) << ' ';
		sum += a;
		++d[a];
	}

	return 0;
}
    