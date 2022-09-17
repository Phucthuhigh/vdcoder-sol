// TONGE

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double n, e = 1;
   long long i = 2;
   cin >> n;
   while (e <= n)
   {
      e = e + double(1) / (i * i);
      ++i;
   }
   cout << setprecision(9) << fixed << e;
   return 0;
}
    