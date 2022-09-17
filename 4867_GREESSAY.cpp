// GREESSAY

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n;
long long r, avg, res, cnt;
pair<long long, long long> b[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n >> r >> avg;
	avg *= n;
	for (int i = 0, a; i < n; ++i)
	{
		cin >> a >> b[i].first;
		b[i].second = max(0LL, r - a);
		res += a;
	}

	sort(b, b + n);
	int i = 0;
	while (i < n && res < avg)
	{
		if (res + b[i].second < avg)
		{
			cnt += b[i].second * b[i].first;
			res += b[i].second;
		}
		else
		{
			cnt += (avg - res) * b[i].first;
			res = avg;
		}
		++i;
	}

	cout << cnt;

	return 0;
}
    