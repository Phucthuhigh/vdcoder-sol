// BRUDAYDB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<long long> a;
void uoc_n(long long n)
{
   a.push_back(1);
   a.push_back(n);
   if (sqrt(n) == (long long)sqrt(n)) a.push_back(sqrt(n));
   for (long long i = 2; i < sqrt(n); ++i)
   {
      if (n % i == 0)
      {
         a.push_back(i);
         a.push_back(n / i);
      }
   }
}
void prime_n(long long n)
{
   bool prime[n];
   for (long i = 0; i < n; ++i) prime[i] = true;
   for (long i = 2; i < n; ++i)
   {
      if (prime[i])
      {
         for (long j = i * i; j < n; j += i) prime[j] = false;
         if (n % i != 0) a.push_back(i);
      }
   }
}
int main()
{
   long long n;
   cin >> n;
   uoc_n(n);
   prime_n(n);
   sort(a.begin(), a.end(), greater<long long>());
   cout << a.size() << '\n';
   for (long i = 0; i < a.size(); ++i) cout << a[i] << ' ';
   return 0;
}
    