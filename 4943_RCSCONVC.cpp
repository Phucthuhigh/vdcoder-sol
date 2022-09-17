// RCSCONVC

#include <iostream>

using namespace std;

long a;

bool dequy(long b, int pos)
{
	if (a > b) return false;
	
	if (a == b)
	{
		cout << "YES\n" << pos << '\n' << a;
		return true;
	}
	
	if (b % 10 == 1)
	{
		if (dequy(b / 10, pos + 1)) cout << ' ' << b;
		else return false;
	}
	else
	{
		if (b % 2 == 0 && dequy(b / 2, pos + 1)) cout << ' ' << b;
		else return false;
	}
	
	return true;
}

int main()
{
	long b;
	cin >> a >> b;
	
	if (b % 10 == 1)
	{
		if (dequy(b / 10, 2)) cout << ' ' << b;
		else cout << "NO";
	}
	else
	{
		if (b % 2 == 0 && dequy(b / 2, 2)) cout << ' ' << b;
		else cout << "NO";
	}
	
	return 0;
}
    