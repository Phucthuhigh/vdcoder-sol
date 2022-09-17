// RCSLT2

#include <iostream>
using namespace std;
int main()
{
   long long n, x, mod = 1000000007;
   cin >> n >> x;
   long long tmp = n, res = 1;
   while (x > 0)
   {
      if (x % 2 == 1) res = (res * tmp) % mod;
      tmp = (tmp * tmp) % mod;
      x /= 2;
   }
   cout << res;
   return 0;
}
    