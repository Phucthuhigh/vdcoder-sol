// VNON

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  long long h, r;
  double pi = 3.141592653589793238462643383279502884;
   cin >> h >> r;
   cout << setprecision(8) << fixed << r * r * h * pi / 3;
   return 0;
}
    