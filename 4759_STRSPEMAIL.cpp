// STRSPEMAIL

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;

	long i = s.find_first_of('@', 0), pre;
	if (s[0] == '@' || s.back() == '@' || i == -1)
	{
		cout << "LAMSAOBAYGIO";
		return 0;
	}

	while (i != -1)
	{
		pre = i;
		i = s.find_first_of('@', i + 1);

		if (i == -1) break;
		if (i - pre <= 2)
		{
			cout << "LAMSAOBAYGIO";
			return 0;
		}
		s.insert(s.begin() + pre + 2, ',');
		++i;
	}
	cout << s;
	return 0;
}
    