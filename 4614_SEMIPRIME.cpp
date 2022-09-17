// SEMIPRIME

#include <iostream>
using namespace std;
long prime[1000000], cnt = 0;
long long n;
bool check[5000000];
void sieve()
{
	for (long long i = 2; i <= n / 2; ++i)
		if (!check[i])
		{
			prime[cnt++] = i;
			for (long long j = i * i; j <= n / 2; j += i) check[j] = true;
		}
}
long long kq()
{
	sieve();
	long long sum = 0;
	for (long i = 0; i < cnt; ++i)
		for (long j = 0; j <= i && prime[i] * prime[j] <= n; ++j) sum += prime[i] * prime[j];
	return sum;
}
int main()
{
//	n = 8900537;
//   cout << n << '\n' << 7416223449709 << '\n' << kq();
	cin >> n;
	cout << n << ' ' << kq();
   return 0;
}
    