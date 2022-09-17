// STRCLOCK

#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	if (n == 12)
	{
		if (s[0] == '0' && s[1] == '0') s[1] = '1';
		if (s[0] == '1' && s[1] > '2') s[1] = '2';
		if (s[0] > '1')	s[0] = (s[1] == '0' ? '1' : '0');
		if (s[3] > '5') s[3] = '5';
	}
	else
	{
		if (s[0] > '2' || (s[0] == '2' && s[1] > '4')) s[0] = '0';
		if (s[3] > '5') s[3] = '5';
	}
	cout << s;
	return 0;
}
    