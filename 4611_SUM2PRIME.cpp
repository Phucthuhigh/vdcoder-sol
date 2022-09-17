// SUM2PRIME

#include <iostream>
#include <cmath>
using namespace std;
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return 1;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return 0;
   for (long long i = 6; i < sqrt(k); i += 6)
      if (k % (i - 1) == 0 || k % (i + 1) == 0) return 0;
   return 1;
}
int main()
{
   long long n, i;
   cin >> n;
   if (n < 4) cout << -1;
   else
   {
      if (n == 4) cout << 2 << ' ' << 2;
      else
      {
         for (i = 3; i <= n / 2; i += 2)
            if (prime(i) && prime(n - i)) break;
         if (i > n / 2) cout << -1;
         else cout << i << ' ' << n - i;
      }
   }
   return 0;
}
    