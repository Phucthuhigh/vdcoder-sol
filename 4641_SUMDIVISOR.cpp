// SUMDIVISOR

#include <iostream>
using namespace std;
long l, r;
long long check[10000001];
void sieve()
{
	for (long long i = 2; i <= r; ++i)
		if (check[i] == 0)
		{
			for (long long j = i + i; j <= r; j += i) check[j] += i;
		}
}
int main()
{
	cin >> l >> r;
	sieve();
	long long sum = 0;
	for (long i = l; i <= r; ++i) sum += check[i];
	cout << sum;
   return 0;
}
    