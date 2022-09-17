// STRSIMPSTR

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	n = s.size();
	s.push_back('0');

	for (int i = 1; i < n; ++i)
	{
		if (s[i] == s[i - 1])
		{
			int j = 0;
			while (j == s[i + 1] - 'a' || j == s[i - 1] - 'a') j = rand() % 26;
			s[i] = char(j + 'a');
		}
	}
	s.pop_back();
	cout << s;
	return 0;
}
    