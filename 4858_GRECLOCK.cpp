// GRECLOCK

#include <iostream>
using namespace std;
int main()
{
	long n;
	cin >> n;
	
	if (n % 2 == 1) 
	{ 
		cout << 7; 
		n -= 3; 
	}
	
	while (n > 0)
	{
		cout << 1;
		n -= 2;
	}

	return 0;
}
    