// DPBOTTLE

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n;
pair<long long, int> max(const pair<long long, int>& a, const pair<long long, int>& b, const pair<long long, int>& c)
{
	pair<long long, int> res = a;
	if (res.first < b.first || (res.first == b.first && res.second > b.second)) res = b;
	if (res.first < c.first || (res.first == c.first && res.second > c.second)) res = c;
	return res;
}
int main()
{
	cin >> n;
	vector<long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	vector<pair<long long, int> > ndrink(n + 1);
	ndrink[0] = {0, 0};
	ndrink[1] = {a[0], 1};
	ndrink[2] = {a[0] + a[1], 2};
	for (int i = 3; i <= n; ++i)
	{
		ndrink[i] = max(ndrink[i - 1], 
			make_pair(ndrink[i - 2].first + a[i - 1], ndrink[i - 2].second + 1),
			make_pair(ndrink[i - 3].first + a[i - 2] + a[i - 1], ndrink[i - 3].second + 2));
	}
	pair<long long, int> res = ndrink[0];
	for (int i = 1; i <= n; ++i) if (res.first < ndrink[i].first || 
	(res.first == ndrink[i].first && res.second > ndrink[i].second)) res = ndrink[i];
	cout << res.second << ' ' << res.first;
	return 0;
}
    