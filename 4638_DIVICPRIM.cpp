// DIVICPRIM

#include <iostream>
using namespace std;
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return true;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return false;
   for (long long i = 5; i * i <= k; i += 6)
      if (k % i == 0 || k % (i + 2) == 0) return false;
   return true;
}
int main()
{
	long long n;
	cin >> n;
	if (n % 2 == 1)
	{
		if (prime(n)) cout << 1;
		else
		{
			if (prime(n - 2)) cout << 2;
			else cout << 3;
		}
	}
	else
	{
		if (n == 2) cout << 1;
		else cout << 2;
	}
	return 0;
}
    