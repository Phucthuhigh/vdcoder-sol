// BTKCOW1

#include <iostream>

using namespace std;

long long a[20];
int n, siz = 21, tmpcnt, dem = 0;

long long tong(long long k)
{
	tmpcnt = 0;
	
	int i = 0;
	long long res = 0;
	
	while (k > 0)
	{
		if (k % 2 == 1)
		{
			res += a[i];
			++tmpcnt;
		}
		k /= 2;
		++i;
	}
	return res;
}

void update()
{
	++dem;
	if (siz > tmpcnt) siz = tmpcnt;
}

int main()
{
	long long m, pown = 1;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) pown *= 2;
	for (int i = 0; i < pown; ++i)
	{
		if (tong(i) == m) update();
	}
	
	if (siz == 21) cout << -1;
	else cout << dem << ' ' << siz;
}
    