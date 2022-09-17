// PTBH

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a, b, c;
   cin >> a >> b >> c;
   double delta = b * b - 4 * a * c;
   if (delta < 0) cout << "VO NGHIEM";
   else
   {
      cout << setprecision(2) << fixed;
      if (delta == 0)
         cout << "PT CO NGHIEM KEP\nX = " << -1 * b / (2 * a);
      else cout << "PT CO HAI NGHIEM\nX1 = " << (-1 * b + sqrt(delta)) / (2 * a) << "\nX2 = " << (-1 * b - sqrt(delta)) / (2 * a);
   }
   return 0;
}
    