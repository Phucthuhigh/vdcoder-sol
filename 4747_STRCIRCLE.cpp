// STRCIRCLE

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	string s;
	cin >> s;
	set<string> a;

	long t = s.size();
	while (t--)
	{
		a.insert(s);
		s = s + s[0];
		s.erase(s.begin());
	}

	cout << a.size();
	return 0;
}
    