// HERON

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
   double a, b, c;
   cin >> a >> b >> c;
   double p = (a + b + c) / 2;
   cout << setprecision(2) << fixed << sqrt(p * (p - a) * (p - b) * (p - c));
   return 0;
}
    