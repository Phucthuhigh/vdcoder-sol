// BRUXAUCON

#include <iostream>
#include <string>
using namespace std;
int main()
{
	long n, m, k, res = 0;
	string s;
	cin >> n >> m >> k >> s;

	for (long len = k; len < m; ++len)
	{
		long dem = 0;
		for (long i = 0; i < len; ++i) if (s[i] == 'A') ++dem;
		if (dem == k) ++res;
		for (long i = len; i < n; ++i)
		{
			if (s[i] == 'A') ++dem;
			if (s[i - len] == 'A') --dem;
			if (dem == k) ++res;
		}
	}
	
	cout << res;
	return 0;
}
    