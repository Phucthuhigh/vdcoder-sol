// RCSHACK

#include <iostream>

using namespace std;

bool checkpow2(long long k)
{
	if (k < 10 && k != 1) return false;
	while (k % 10 == 0) k /= 10;
	while (k > 1)
	{
		if (k % 2 == 1) return false;
		k /= 2;
	}
	
	return true;
}

int main()
{
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (checkpow2(n)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
    