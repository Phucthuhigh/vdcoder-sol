// BTKBRACK

#include <iostream>
#include <string>
#include <vector>
using namespace std;
long n;
vector<string> a;
void dayngoacdung(string s, long dem)
{
	if (n == s.size())
	{
		a.push_back(s);
		return;
	}

	if (dem == 0)
	{
		dayngoacdung(s + '(', 1);
		return;
	}

	if (n - s.size() == dem)
	{
		dayngoacdung(s + ')', dem - 1);
		return;
	}

	dayngoacdung(s + '(', dem + 1);
	dayngoacdung(s + ')', dem - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	if (n % 2 == 1) cout << 0;
	else
	{
		dayngoacdung("", 0);
		cout << a.size() << '\n';
		for (long i = 0; i < a.size(); ++i)
			cout << a[i] << '\n';
	}
	return 0;
}
    