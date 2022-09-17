// TGGI

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   double a, b, c, ab2, bc2, ca2, a2, b2, c2;
   long can = 0;
   cin >> a >> b >> c;
   a2 = a * a;
   b2 = b * b;
   c2 = c * c;
   ab2 = a2 + b2;
   bc2 = b2 + c2;
   ca2 = c2 + a2;
   a2 = roundf(a2 * 100000) / 100000;
   b2 = roundf(b2 * 100000) / 100000;
   c2 = roundf(c2 * 100000) / 100000;
   ab2 = roundf(ab2 * 100000) / 100000;
   bc2 = roundf(bc2 * 100000) / 100000;
   ca2 = roundf(ca2 * 100000) / 100000;
   if ((a + b > c) && (b + c > a) && (c + a > b))
   {
      if (a == b) ++can;
      if (b == c) ++can;
      if (c == a) ++can;
      if (ab2 == c2 || bc2 == a2 || ca2 == b2)
      {
         cout << "VUONG";
         if (can == 1) cout << " CAN";
      }
      else
      {
      	switch (can)
      	{
      	   case 0: cout << "THUONG"; break;
      	   case 1: cout << "CAN"; break;
      	   case 3: cout << "DEU"; break;
      	}
      }
   }
   else cout << "KHONGPHAITAMGIAC";
   return 0;
}
    