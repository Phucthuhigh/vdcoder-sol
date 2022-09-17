// GREDINNER

#include <iostream>
using namespace std;
long n, m;
long max(long x, long y) { if (x > y) return x; return y; }
long min(long x, long y) { if (x < y) return x; return y; }
long mindailo()
{
	long len = n, t, minn = 1000000007;
	while (len--)
	{
		cin >> t;
		minn = min(minn, t);
	}
	return minn;
}
int main()
{
	cin >> m >> n;
	long maxx = 0;
	while (m--)
	{
		maxx = max(maxx, mindailo());
	}
	cout << maxx;
}
    