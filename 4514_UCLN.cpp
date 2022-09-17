// UCLN

#include <iostream>
using namespace std;
int main()
{
   long long a, b;
   cin >> a >> b;
   long long dividend = a >= b ? a : b;
   long long divisor = a <= b ? a : b;
   while (divisor != 0)
   {
      long long remainder = dividend % divisor;
      dividend = divisor;
      divisor = remainder;
   }
   cout << dividend;
   return 0;
}
    