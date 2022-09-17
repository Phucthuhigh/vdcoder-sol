// TONGUOC

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   long long k, n, sum, dem;
   cin >> k;
   for (long long i = 0; i < k; ++i)
   {
      cin >> n;
      sum = 1 + n;
      dem = 2;
      if (sqrt(n) == (long long)sqrt(n)) 
      {
         sum += sqrt(n); 
         ++dem;
      }
      for (long long i = 2; i < sqrt(n); ++i)
      {
         if (n % i == 0) 
         {
            sum = sum + i + n / i;
            dem += 2;
         }
      }
      cout << n << " co " << dem << " uoc. Tong uoc la: " << sum << '\n';
   }
   return 0;
}
    