// BRUWATER

#include <iostream>
using namespace std;
long long a[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	long n, m;
	cin >> n >> m;
	
	long x, y, c;
	while (m--)
	{
		cin >> x >> y >> c;
		a[x - 1] += c;
		a[y] -= c;
	}

	long long sum = 0;
	for (long i = 0; i < n; ++i)
	{
		sum += a[i];
		cout << sum << ' ';
	}
	
	return 0;
}
    