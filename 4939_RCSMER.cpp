// RCSMER

#include <iostream>
#include <string>
using namespace std;
string minn = "a", maxx = " ", a, b;
void dequy(int i, int j, string s)
{
	if (i == a.size() && j == b.size())
	{
		if (minn > s) minn = s;
		if (maxx < s) maxx = s;
		return;
	}
	if (i < a.size()) dequy(i + 1, j, s + a[i]);
	if (j < b.size()) dequy(i, j + 1, s + b[j]);
}
int main()
{
	cin >> a >> b;
	dequy(0, 0, "");
	cout << minn << '\n' << maxx;
	return 0;
}
    