// STRINSTR

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = (int)1e6 + 5, mod = (int)1e9 + 7;
int m, n, kmp[N];
string s, t;

void build_kmp(const string& s)
{
	kmp[0] = 0;
	for (int i = 1, j = 0; i < m; ++i)
	{
		while (s[i] != s[j] && j > 0)
			j = kmp[j - 1];

		if (s[i] == s[j])
			kmp[i] = ++j;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	s = t + "#" + s;
	m = s.size(), n = t.size();

	build_kmp(s);
	int d = 0;
	for (int i = t.size(); i < m; ++i)
	{
		if (kmp[i] == n) ++d, i += n - 1;
	}
	cout << d;
	return 0;
}
    