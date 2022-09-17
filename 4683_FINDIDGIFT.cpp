// FINDIDGIFT

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
queue< pair<long, long> > a;
long n, k, f[100001];
int main()
{
	cin >> n >> k;
	long long tmp = 0;
	for (long i = 1, t; i <= n; ++i)
	{
		cin >> t;
		a.push(make_pair(t, i));
		f[i] = t;
		tmp += t;
	}
	if (k > tmp) cout << k - tmp;
	if (k == tmp) cout << "OK";
	if (k < tmp)
	{
		sort(f + 1, f + n + 1);
		long i = 1, sum = 0;
		while (f[i] * (n - i + 1) + sum <= k) 
		{
			sum += f[i];
			++i;
		}
		--i;

		k -= f[i] * n;
		for (long j = 1; j <= n; )
		{
			pair<long, long> t = a.front();
			a.pop();
			t.first -= f[i];
			if (t.first <= 0)
			{
				k -= t.first;
				--n;
			}
			else
			{
				++j;
				a.push(t);
			}
		}
		long cnt = k / n + 1;
		k %= a.size();
		while (k--)
		{
			pair<long, long> t = a.front();
			a.pop();
			t.first -= cnt;
			if (t.first > 0) a.push(t);
		}
		while (!a.empty())
		{
			pair<long, long> t = a.front();
			a.pop();
			cout << t.second << ' ';
		}
	}
	return 0;
}
    