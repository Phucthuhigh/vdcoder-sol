// DPGRKI2

#include <iostream>
#include <vector>
using namespace std;
long long max(long long a, long long b, long long c)
{
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	long m, n;
	cin >> m >> n;
	vector< vector<long long> > arr(m + 1);
	for (long i = 1; i <= m; ++i)
	{
		arr[i].resize(n);
		for (long j = 0; j < n; ++j) cin >> arr[i][j];
	}
	
	vector<long long> a(m + 1);
	for (long i = 1; i <= m; ++i) 
	{
		a[i] = arr[i][0];
	}
	
	for (long j = 1; j < n; ++j)
	{
		vector<long long> tmp(m + 2);
		for (long i = 1; i <= m; ++i) tmp[i] = a[i];	
		tmp[0] = tmp[1];
		tmp[m + 1] = tmp[m];
		
		for (long i = 1; i <= m; ++i)
		{
			a[i] = max(tmp[i - 1], tmp[i], tmp[i + 1]) + arr[i][j];
		}
	}
	long long maxx = a[1];
	for (long i = 2; i <= m; ++i) if (maxx < a[i]) maxx = a[i];
	cout << maxx;
	return 0;
}
    