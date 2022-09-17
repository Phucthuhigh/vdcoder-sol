// DPLCS1

#include <iostream>
#include <string>
using namespace std;
long f[2001][2001];
long max(const long& x, const long& y) { if (x > y) return x; return y; }
int main()
{
	string a, b;
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	for (long i = 1; i < a.size(); ++i)
		for (long j = 1; j < b.size(); ++j)
			if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	cout << f[a.size() - 1][b.size() - 1];
	return 0;
}
    