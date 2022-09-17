// DPRCDIE

#include <iostream>
using namespace std;
long hp, a;
long kq()
{
	long res = 0;
	while (hp > 0 && a > 0)
	{
		if (hp <= 2) break;
		if (a > 8)
		{
			hp -= 2;
			a -= 8;
			++res;
			continue;
		}
		if (hp <= 17) break;
		hp -= 17;
		a += 7;
		++res;
	}
	return res;
}
int main()
{
	long t;
	cin >> t;
	while (t--)
	{
		cin >> hp >> a;
		cout << 2 * kq() + 1 << '\n';
	}
}
    