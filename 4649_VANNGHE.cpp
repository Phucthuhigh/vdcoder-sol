// VANNGHE

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
   long long m, n, tmp;
   cin >> m >> n;
   tmp = ucln(m, n);
   cout << "So to: " << tmp << "\nSo nam moi to: " << m / tmp << "\nSo nu moi to: " << n / tmp;
   return 0;
}
    