// BRUMAYMAN

#include <iostream>
#include <algorithm>
using namespace std;
long long lucky[2*2*2*2*2*2*2*2*2*2 - 2], maxl = 1000000000, cnt = 0;
void setlucky(long long k)
{
	if (k * 10 < maxl)
	{
		lucky[cnt++] = k;
		setlucky(k * 10 + 6);
		setlucky(k * 10 + 8);
	}
}
int main()
{
	setlucky(6);
	setlucky(8);
	sort(lucky, lucky + cnt);
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long i = 0;
		while (i < cnt && lucky[i] <= n)
		{
			if (n % lucky[i] == 0) break;
			++i;
		}
		if (i < cnt && n % lucky[i] == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
    