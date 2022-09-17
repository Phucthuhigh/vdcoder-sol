// BRUMSQUARE

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string n;
long max(long x, long y) { if (x > y) return x; return y; }
long min(long x, long y) { if (x < y) return x; return y; }
bool check(long k)
{
	long i = 0;
	string t = n;
	while (k > 0)
	{
		if (k % 2 == 1)
		{
			t.erase(t.end() - 1 - i);
		}
		else ++i;
		k /= 2;
	}

	if (t[0] == '0') return false;
	long checkt = 0;
	for (long i = t.size() - 1, tmp = 1; i >= 0; --i)
	{
		checkt += (t[i] - '0') * tmp;
		tmp *= 10;
	}

	if (sqrt(checkt) == (long)sqrt(checkt)) return true;
	return false;
}
long dem1(long k)
{
	long d = 0;
	while (k > 0)
	{
		if (k % 2 == 1) ++d;
		k /= 2;
	}
	return d;
}
int main()
{
	cin >> n;

	long lenn = n.length(), np = 1, minn = 20;
	for (long i = 0; i < lenn; ++i) np *= 2;
	--np;

	for (long i = 0; i < np; ++i)
		if (check(i)) minn = min(minn, dem1(i));
	if (minn == 20) minn = -1;

	cout << minn;
	return 0;
}
    