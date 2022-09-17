// PTBACNHAT

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double a, b;
   cin >> a >> b;
   if (a == 0)
   {
      if (b == 0) cout << "VO SO NGHIEM";
      else cout << "VO NGHIEM";
   }
   else cout << setprecision(2) << fixed << "PT CO NGHIEM\nX = " << -1 * b / a;
   return 0;
}
    