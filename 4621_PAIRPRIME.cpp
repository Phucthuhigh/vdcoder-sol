// PAIRPRIME

#include <iostream>
#include <cmath>
using namespace std;
long pri[3402], sang[31623];
void set_pri()
{
	for (long i = 3; i < 178; i += 2)
	{
		if (!sang[i])
		{
			long k = 2 * i;
			for (long j = i * i; j < 31623; j += k) sang[j] = true;
		}
	}
	pri[0] = 2;
	long cnt = 1;
	for (long i = 3; i < 31623; i += 2)
		if (!sang[i]) pri[cnt++] = i;
	pri[cnt] = 1000000007;
}
bool prime(long k)
{
   if (k < 2) return false;
   
   long m = (long)sqrt(k);
   
   for (long i = 0; pri[i] <= m; ++i)
      if (k % pri[i] == 0) return false;
   return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	set_pri();
	long n, t_prime = 0, tmp;
	cin >> n;
	for (long i = 0; i < n; ++i) 
	{
    	cin >> tmp;
    	if (prime(tmp)) ++t_prime;
	}
	cout << 1LL * t_prime * (n - t_prime) + 1LL * t_prime * (t_prime - 1) / 2;
	return 0;
}
    