// CHINUOC

#include <iostream>
using namespace std;
long long prime[10000], cnt = 0, n;
bool check[20000];
void sieve()
{
	for (long long i = 2; i * i <= n / 4; ++i)
		if (!check[i])
		{
			prime[cnt++] = i;
			for (long long j = i * i; j * j <= n / 4; j += i) check[j] = true;
		}
}
long long kq()
{
	sieve();
	long long d = 0;
	for (long i = 0; i < cnt; ++i)
		for (long j = 0; j < i && prime[i] * prime[i] * prime[j] * prime[j] <= n; ++j) ++d;
	for (long i = 0; prime[i] * prime[i] * prime[i] * prime[i] * prime[i] * prime[i] * prime[i] * prime[i] <= n; ++i) ++d;
	return d;
}
int main()
{
	cin >> n;
	cout << kq();
   return 0;
}
    