// RCSSQRT

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double can(double n)
{
   if (n == 1) return 1;
   return sqrt(n + can(n - 1));
}
int main()
{
   long long n;
   cin >> n;
   cout << setprecision(3) << fixed << can(double(n));
   return 0;
}
    