// STREQUALI

#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long q;
	string s, t;
	bool a[256], b[256];
	bool flag;
	cin >> q;
	while (q--)
	{
		flag = false;
		cin >> s >> t;
		for (long i = 0; i < 256; ++i) { a[i] = b[i] = false; }
		for (long i = 0; i < s.size(); ++i) { a[s[i]] = b[t[i]] = true; }
		for (long i = 0; i < 256; ++i)
		{
			if (a[i] && b[i]) { flag = true; break; }
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
    