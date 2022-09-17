// DPVOI

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct ele
{
	long w, iq, stt;
} a[5001];
long long f[5001];
long pre[5001];
int main()
{
	long n = 0;
	while (cin >> a[n].w)
	{
		if (a[n].w == 0) break;
		cin >> a[n].iq;
		a[n].stt = n + 1;
		++n;
	}

	sort(a, a + n, [](const ele& x, const ele& y) {return x.w < y.w; } );

	long long maxx;
	for (long i = 0, pmax; i < n; ++i)
	{
		maxx = 0;
		pmax = -1;
		for (long j = 0; j < i; ++j)
		{
			if (a[j].w < a[i].w && a[j].iq > a[i].iq)
			{
				if (maxx < f[j])
				{
					maxx = f[j];
					pmax = j;
				}
			}
		}
		f[i] = maxx + 1;
		pre[i] = pmax;
	}

	maxx = f[0];
	long pmax = -1;
	for (long i = 1; i < n; ++i)
	{
		if (maxx < f[i])
		{
			maxx = f[i];
			pmax = i;
		}
	}

	stack<long> kq;
	while (pmax != -1)
	{
		kq.push(a[pmax].stt);
		pmax = pre[pmax];
	}
	cout << kq.size() << '\n';
	while (!kq.empty())
	{
		cout << kq.top() << ' ';
		kq.pop();
	}
	return 0;
}
    