// SumPrime

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> prime;
void sieve_prime()
{
   long max_sieve = 1000001;
   long long d = 0;
   prime.resize(max_sieve);
   for (long i = 0; i < max_sieve; ++i) prime[i] = 0;
   for (long i = 2; i < max_sieve; ++i)
   {
      if (prime[i] == 0) 
      {
         d += i;
         for (long long j = 1LL * i * i; j < max_sieve; j += i) prime[j] += 1;
      }
      prime[i] = d;
   }
}
int main()
{
   ios_base::sync_with_stdio(0);
   sieve_prime();
   long long t, n;
   cin >> t;
   for (long i = 0; i < t; ++i) 
   {
      cin >> n;
      cout << prime[n] << '\n';
   }
   return 0;
}
    