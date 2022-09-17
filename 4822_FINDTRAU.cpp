// FINDTRAU

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const long double oo = 1e9 + 7;
long double a1, b1, a2, b2;

#define sqr(x) (x) * (x)
long double cal(long double x)
{
	return (sqrt(sqr(x - a1) + sqr(b1)) + sqrt(sqr(x - a2) + sqr(b2)));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a1 >> b1 >> a2 >> b2;
	long double l = -oo, r = oo, mid1, mid2;
	for (int i = 0; i < 90; ++i)
	{
		mid1 = (l + l + r) / 3;
		mid2 = (l + r + r) / 3;
		if (cal(mid1) > cal(mid2)) l = mid1;
		else r = mid2;
	}
	cout << fixed << setprecision(5) << l;
	return 0;
}
    