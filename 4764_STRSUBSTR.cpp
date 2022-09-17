// STRSUBSTR

#include <iostream>
#include <string>

using namespace std;

int k = 97; // 'z' = 122
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> s;
	for (int i = 0; k < 123 && i < s.size(); ++i)
	{
		if (s[i] <= k)
			s[i] = (char)k++;
	}

	cout << (k == 123 ? s : "-1");

	return 0;
}
    