// BRUHAIGRAM

#include <iostream>
using namespace std;
char s[100];
bool check[25 * 26 + 25];
int main()
{
	long n, maxd = 0, td;
	char s1 = 64, s2 = 64;
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> s[i];
	for (long i = 1; i < n; ++i)
	{
		if (!check[(s[i - 1] - 'A') * 26 + (s[i] - 'A')])
		{
			check[(s[i - 1] - 'A') * 26 + (s[i] - 'A')] = true;
			td = 0;
			for (long j = i; j < n; ++j) if (s[i - 1] == s[j - 1] && s[i] == s[j]) ++td;
			if (td > maxd)
			{
				maxd = td;
				s1 = s[i - 1];
				s2 = s[i];
			}
			else
			{
				if (td == maxd && s[i - 1] * 26 + s[i] < s1 * 26 + s2)
				{
					s1 = s[i - 1];
					s2 = s[i];
				}
			}
		}
	}
	cout << s1 << s2;
	return 0;
}
    