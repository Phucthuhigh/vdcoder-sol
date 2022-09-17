// GRESNOW

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)1e5 + 7;

int n, cnt, res[N][3];
unordered_map<int, int> SnowBall;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> n;
	for (int i = 0, a; i < n; ++i)
	{
		cin >> a;
		++SnowBall[a];
	}

	priority_queue<pii> q;
	for (unordered_map<int, int>::iterator it = SnowBall.begin(); it != SnowBall.end(); ++it)
		q.push(mp(it->second, it->first));

	while (q.size() >= 3)
	{
		pii a = q.top(); q.pop();
		pii b = q.top(); q.pop();
		pii c = q.top(); q.pop();

		++cnt;
		res[cnt][0] = a.second;
		res[cnt][1] = b.second;
		res[cnt][2] = c.second;
		sort(res[cnt], res[cnt] + 3);

		if (--a.first > 0) q.push(a);
		if (--b.first > 0) q.push(b);
		if (--c.first > 0) q.push(c);
	}

	cout << cnt << '\n';
	for (int i = 1; i <= cnt; ++i)
		cout << res[i][2] << ' ' << res[i][1] << ' ' << res[i][0] << '\n';

	return 0;
}
    