// DPWAVIO

#include <iostream>
#include <vector>
using namespace std;
vector<long long> a, b, t, g;
long long maxa = 100000007;
long n;
long binsearch(long long k)
{
	long l = 1, r = b.size() - 1, mid, res = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (b[mid] == k) return mid - 1;
		if (b[mid] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
void set_t()
{
	b.clear();
	b.push_back(-maxa);
	for (long i = 1, k; i <= n; ++i)
	{
		k = binsearch(a[i]);
		if (k == b.size() - 1) b.push_back(a[i]);
		else
		{
			if (a[i] < b[k + 1]) b[k + 1] = a[i];
		}
		t[i] = k;
	}
}
void set_g()
{
	b.clear();
	b.push_back(-maxa);
	for (long i = n, k; i > 0; --i)
	{
		k = binsearch(a[i]);
		if (k == b.size() - 1) b.push_back(a[i]);
		else
		{
			if (a[i] < b[k + 1]) b[k + 1] = a[i];
		}
		g[i] = k;
	}
}
long max(long x, long y) { if (x > y) return x; return y; }
int main()
{
	cin >> n;
	a.resize(n + 1);
	t.resize(n + 1);
	g.resize(n + 1);
	for (long i = 1; i <= n; ++i) cin >> a[i];
	long maxx = 1;
	set_t();
	set_g();
	for (long i = 2; i < n; ++i) if (t[i] != 0 && g[i] != 0) maxx = max(maxx, t[i] + g[i] + 1);
	cout << maxx;
	return 0;
}
    