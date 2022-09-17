// CUTCAKE

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
   long long n, max = 360;
   cin >> n;
   for (long long i = 0, tmp; i < n; ++i)
   {
      cin >> tmp;
      max = ucln(max, tmp);
   }
   long long sum = 360 / max - n - 1;
   if (sum < 0) sum = 0;
   cout << sum;
   return 0;
}
    