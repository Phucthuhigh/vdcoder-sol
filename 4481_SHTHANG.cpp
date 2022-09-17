// SHTHANG

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   double a, b, c, h, anpha, pi = 3.141592653589793238462643383279502884;
   cin >> b >> a >> anpha;
   anpha = anpha * pi / 180;
   h = ((a - b) / 2) * tan(anpha);
   cout << setprecision(4) << fixed << (((a - b) / 2) / cos(anpha)) * 2 + a + b << '\n' << (a + b) * h / 2;
   return 0;
}
    