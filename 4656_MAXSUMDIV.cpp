// MAXSUMDIV

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
long long min(long long a, long long b)
{
   if (a < b) return a; else return b;
}
int main()
{
   long long n, a, b, x, y, tmp, sum;
   cin >> n >> a >> b >> x >> y;
   tmp = a / ucln(a, b) * b;
   sum = n / a * x + n / b * y - n / tmp * min(x, y);
   cout << sum;
   return 0;
}
    