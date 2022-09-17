// GCD2ONE

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
   long long n, max;
   cin >> n >> max;
   for (long long i = 1, tmp; i < n; ++i)
   {
      cin >> tmp;
      max = ucln(max, tmp);
   }
   if (max == 1) cout << 0;
   else cout << -1;
   return 0;
}
    