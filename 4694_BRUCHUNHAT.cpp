// BRUCHUNHAT

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double min(double a, double b) { if (a < b) return a; return b; }
int main()
{
   cout << setprecision(1) << fixed;
   long long a, b;
   cin >> a >> b;
   double min_ = (double)a / 2 * b;
   cout << min_ << '\n';
   for (long i = 0; i <= b; ++i)
   {
      double x = i, mc = b - x, 
      a1 = sqrt(a * a + x * x),
      b1 = sqrt(b * b + (a - x) * (a - x)), 
      c1 = sqrt(x * x + mc * mc), 
      p1 = (a1 + b1 + c1) / 2, 
      tmp = sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
      if (min_ > tmp) min_ = tmp;
   }
   cout << min_;
   return 0;
}
    