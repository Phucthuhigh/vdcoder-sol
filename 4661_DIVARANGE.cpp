// DIVARANGE

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
   long long n, l, r, bcnn_ = 1;
   cin >> n >> l >> r;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      bcnn_ = bcnn(bcnn_, tmp);
   }
   cout << r / bcnn_ - ((l + bcnn_ - 1) / bcnn_) + 1;
   return 0;
}
    