// BRUTENNUM

#include <iostream>
using namespace std;
bool tennum(long k)
{
	long s = 0;
	while (k > 0)
	{
		s += k % 10;
		k /= 10;
	}
	return (s == 10);
}
int main()
{
	ios_base::sync_with_stdio(false);
	long k;
	cin >> k;
	
	long d = 0, i = 10;
	while (d < k)
	{
		i += 9;
		if (tennum(i)) ++d;
	}
	cout << i;
}
    