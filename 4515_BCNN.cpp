// BCNN

#include <iostream>
using namespace std;
int main()
{
   long long a, b, n, m;
   cin >> m >> n;
   a = m;
   b = n;
   long long dividend = a >= b ? a : b;
   long long divisor = a <= b ? a : b;
   while (divisor != 0)
   {
      long long remainder = dividend % divisor;
      dividend = divisor;
      divisor = remainder;
   }
   cout << m / dividend * n;
   return 0;
}
    