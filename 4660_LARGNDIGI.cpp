// LARGNDIGI

#include <iostream>
using namespace std;
long long bcnn(long long a, long long b)
{
   long long m = a, n = b;
   long long dividend = a >= b ? a : b;
   long long divisor = a <= b ? a : b;
   while (divisor != 0)
   {
      long long remainder = dividend % divisor;
      dividend = divisor;
      divisor = remainder;
   }
   return m / dividend * n;
}
int main()
{
   long long a, b, c, n, bcnn_, max_n = 0, min_n = 1;
   cin >> a >> b >> c >> n;
   bcnn_ = bcnn(bcnn(a, b), c);
   for (long long i = 0, tmp = 9; i < n; ++i)
   {
      max_n += tmp;
      tmp *= 10;
      min_n *= 10;
   }
   min_n /= 10;
   if (bcnn_ > max_n) cout << -1;
   else 
   {
      long long tmp = max_n / bcnn_ * bcnn_;
      if (tmp < min_n) cout << -1;
      else cout << tmp;
   }
   return 0;
}
    