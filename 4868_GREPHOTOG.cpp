// GREPHOTOG

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, d, a, b, res[100005], cnt;
string s;
pair<int, int> arr[100005];

int main()
{
	cin >> n >> d >> a >> b;
	for (int i = 0, x, y; i < n; ++i)
	{
		cin >> x >> y;
		arr[i] = { x * a + y * b, i + 1 };
	}

	sort(arr, arr + n);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i].first;
		if (sum <= d)
		{
			res[cnt++] = arr[i].second;
		}
	}

	sort(res, res + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; ++i)
		cout << res[i] << ' ';

	return 0;
}
    