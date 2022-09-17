// DPLIQ2

#include <iostream>
#include <stack>
using namespace std;
long long a[5001], b[5001], pre[5001], maxa = 1000000007, len = 0;
long binsearch(long long k)
{
	long l = 1, r = len, mid, res = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[b[mid]] < k)
		{
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return res;
}
int main()
{
	long n;
	cin >> n;
	a[0] = -maxa;
	for (long i = 1; i <= n; ++i) cin >> a[i];
	for (long i = 1; i <= n; ++i)
	{
		long k = binsearch(a[i]);
		if (k == len) b[++len] = i;
		else b[k + 1] = i;
		pre[i] = b[k];
	}
	stack<long> kq;
	long k = b[len];
	while (k)
	{
		kq.push(k);
		k = pre[k];
	}
	cout << kq.size() << '\n';
	while (!kq.empty())
	{
		cout << kq.top() << ' ';
		kq.pop();
	}
	return 0;
}
    