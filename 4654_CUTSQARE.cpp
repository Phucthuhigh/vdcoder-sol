// CUTSQARE

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
   long long a, b, tmp;
   cin >> a >> b;
   tmp = ucln(a, b);
   cout << a / tmp * b / tmp;
   return 0;
}
    