// CNTPRIME1

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long k, max_sieve = -2;
vector<long long> a, b, prime;
void sieve_prime()
{
   long d = 0;
   ++max_sieve;
   prime.resize(max_sieve);
   for (long i = 0; i < max_sieve; ++i) prime[i] = 0;
   for (long i = 2; i < max_sieve; ++i)
   {
      if (prime[i] == 0) 
      {
         for (long long j = 1LL * i * i; j < max_sieve; j += i)
            prime[j] = 1;
         ++d;
      }
      prime[i] = d;
   }
}
int main()
{
   cin >> k;
   a.resize(k);
   b.resize(k);
   for (long i = 0; i < k; ++i) 
   {
      cin >> a[i] >> b[i];
      if (max_sieve < b[i]) max_sieve = b[i];
   }
   sieve_prime();
   for (long i = 0; i < k; ++i)
   {
      cout << prime[b[i]] - prime[a[i] - 1] << '\n';
   }
   return 0;
}
    