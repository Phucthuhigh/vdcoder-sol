// SPIRALPRIM

#include <iostream>
#include <vector>
using namespace std;
long n, dem = 0;
void sieve()
{
	vector<bool> check(n + 1, true);
	for (long long i = 2; i <= n; ++i)
		if (check[i])
		{
			++dem;
			for (long long j = i * i; j <= n; j += i) check[j] = false;
		}
}
void xuat (long x, long y) { cout << x << ' ' << y; }
int main()
{
	cin >> n;
	sieve();
	--dem;
	long tmp = 7;
	while (dem >= tmp)
	{
		dem -= tmp;
		tmp += 8;
	}
	long x = 0, y = -tmp/8, ngang1 = -y + 1, doc1 = -2 * y + 1, ngang2 = ngang1 * 2, doc2 = ngang2; // ngang3 = ngang1
	if (dem > ngang1) { dem -= ngang1; x += ngang1; }
	else { xuat(x + dem, y); return 0; }
	if (dem > doc1) { dem -= doc1; y += doc1; }
	else { xuat(x, y + dem); return 0; }
	if ( dem > ngang2) { dem -= ngang2; x -= ngang2; }
	else { xuat(x - dem, y); return 0; }
	if (dem > doc2) { dem -= doc2; y -= doc2; }
	else { xuat(x, y - dem); return 0; }
	xuat(x + dem, y);
	return 0;
}
    