// BRUQUANXE

#include <iostream>

using namespace std;

bool ngang[100001], doc[100001];

int main()
{
	long n, m;
	cin >> n >> m;
	
	long dngang = n, ddoc = n;
	
	for (long i = 0, x, y; i < m; ++i)
	{
		cin >> x >> y;
		if (!doc[x]) { doc[x] = true; --ddoc; }
		if (!ngang[y]) {ngang[y] = true; --dngang; }
		cout << 1LL * dngang * ddoc << ' ';
	}
	
	return 0;
}
    