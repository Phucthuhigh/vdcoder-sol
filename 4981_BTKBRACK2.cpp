// BTKBRACK2

#include <iostream>
#include <string>
#include <set>
using namespace std;
long n;
string t;
set<string> a;
long check(char c)
{
	if (c == '(') return 1;
	return -1;
}
void dayngoacdung(string s, long dem, long i)
{
	if (dem < 0) return;

	if (i >= n)
	{
		if (dem == 0 && s.size() > 0) a.insert(s);
		return;
	}
	
	dayngoacdung(s + t[i], dem + check(t[i]), i + 1);
	dayngoacdung(s, dem, i + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> t;
	n = t.size();

	dayngoacdung("", 0, 0);

	cout << a.size() << '\n';
	
	for (set<string>::iterator i = a.begin(); i != a.end(); ++i)
		cout << *i << '\n';

	return 0;
}
    