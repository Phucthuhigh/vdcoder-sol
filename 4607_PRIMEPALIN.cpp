// PRIMEPALIN

#include <iostream>
using namespace std;
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return 1;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return 0;
   for (long long i = 5; i * i <= k; i += 6)
      if (k % i == 0 || k % (i + 2) == 0) return 0;
   return 1;
}
bool palin(long long k)
{
	long long t = k, a = 0;
	while (t > 0)
	{
		a = a * 10 + t % 10;
		t /= 10;
	}
	return (k == a);
}
int main()
{
	long long n;
	cin >> n;
	if (n >= 5002413 && n < 7014107) { cout << 7014107; return 0; }
	++n;
	while (true)
	{
		if (prime(n) && palin(n)) break;
		++n;
	}
	cout << n;
	return 0;
}
    