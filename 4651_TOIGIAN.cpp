// TOIGIAN

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
void rutgonphanso(long long &a, long long &b)
{
   long long tmp = ucln(a, b);
   a /= tmp;
   b /= tmp;
}
void congphanso(long long &a, long long &b, long long c, long long d)
{
   long long tmp = b / ucln(b, d) * d;
   a = tmp / b * a;
   c = tmp / d * c;
   a += c;
   b = tmp;
   rutgonphanso(a, b);
}
int main()
{
   long long a, b, c, d;
   while (cin >> a >> b >> c >> d)
   {
      rutgonphanso(a, b);
      rutgonphanso(c, d);
      congphanso(a, b, c, d); // return a / b
      cout << a << '/' << b << '\n';
   }
   return 0;
}
    