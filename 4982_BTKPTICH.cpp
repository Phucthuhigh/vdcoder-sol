// BTKPTICH

#include <iostream>
#include <string>
#include <vector>
using namespace std;
long n;
vector<string> a;
string chuyenstring(long k)
{
	string t = "";
	while (k > 0)
	{
		t = t + char(k % 10 + '0');
		k /= 10;
	}
	string s = "";
	for (long i = 0; i < t.size(); ++i)
		s = t[i] + s;
	return s;
}
void phantichso(string s, long conlai, long pre)
{
	for (long i = pre; i <= conlai / 2; ++i)
	{
		phantichso(s + chuyenstring(i) + char('+'), conlai - i, i);
	}
	a.push_back(" = " + s + chuyenstring(conlai));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;

	phantichso("", n, 1);
	
	for (long i = 0; i < a.size(); ++i)
		cout << n << a[i] << '\n';

	return 0;
}
    