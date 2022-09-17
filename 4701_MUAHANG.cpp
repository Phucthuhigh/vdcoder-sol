// MUAHANG

#include <iostream>
#include <algorithm>
using namespace std;
long a[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	long n;
	long long s;
	cin >> n >> s;
	for (long i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);
	
	long long sum = 0;
	for (long i = 0; i < n; ++i)
	{
		if (sum + a[i] * (n - i) >= s) { cout << (s - sum + n - i - 1) / (n - i); return 0; }
		else sum += a[i];
	}
	
	cout << -1;
	return 0;
}
    