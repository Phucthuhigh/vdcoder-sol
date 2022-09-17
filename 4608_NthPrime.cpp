// NthPrime

#include <iostream>
#include <vector>
using namespace std;
vector<long long> prime;

bool check_prime(long long k)
{
   for (long i = 0; i < prime.size(); ++i)
   {
      if (k < prime[i] * prime[i]) return true;
      if (k % prime[i] == 0) return false;
   }
   return true;
}
void set_prime()
{
   prime.push_back(2);
   long long lim = 100001, i = 3;
   while (prime.size() < lim)
   {
      if (check_prime(i)) prime.push_back(i);
      i += 2;
   }
}
int main()
{
   ios_base::sync_with_stdio(false);
   
   set_prime();
   
   long long t;
   cin >> t;
   for (long i = 0, n; i < t; ++i)
   {
      cin >> n;
      cout << prime[n - 1] << '\n';
   }
   return 0;
}
    