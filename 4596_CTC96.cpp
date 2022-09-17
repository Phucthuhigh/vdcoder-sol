// CTC96

#include <iostream>
using namespace std;
long long ucln(long long a, long long b)
{
   long long dividend = a >= b ? a : b;
   long long divisor = a <= b ? a : b;
   while (divisor != 0)
   {
      long long remainder = dividend % divisor;
      dividend = divisor;
      divisor = remainder;
   }
   return dividend;
}
int main()
{
   long long a, b, c, d;
   cin >> a >> b >> c >> d;
   cout << ucln(ucln(a, b), ucln(c, d));
   return 0;
}
    