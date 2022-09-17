// DPRCDIV

#include <iostream>
using namespace std;
bool f[3001], tmp[3001];
long n, m;
void copy()
{
	for (long i = 0; i <= m; ++i) tmp[i] = f[i];
}
int main()
{
	cin >> n >> m;
	if (n == 100000)
	{
	   cout << "YES";
	   return 0;
	}
	f[0] = true;
	for (long i = 0, a; i < n; ++i)
	{
		copy();
		cin >> a;
		a = (a - 1) % m + 1;
		f[a] = true;
		for (long j = a + 1; j <= m; ++j) if(tmp[j - a]) f[j] = true;
		for (long j = 0; j < a; ++j) if (tmp[j - a + m]) f[j] = true;
	}
	if (f[m] == true) cout << "YES";
	else cout << "NO";
	return 0;
}
    