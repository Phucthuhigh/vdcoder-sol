// BRUTHBIEN2

#include <iostream>
using namespace std;
int main()
{
	long n, t, m;
	cin >> n >> t >> m;
	
	long l = 0, r = 0, c, dem = 0;
	while (r < n)
	{
		cin >> c;
		++r;
		if (c > t) l = r;
		if (r - l >= m) ++dem;
	}
	
	cout << dem;
	return 0;
}
    