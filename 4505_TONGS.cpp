// TONGS

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   double tmp = 1, sum = 1;
   for (long long i = 2; i <= n; ++i)
   {
      tmp = tmp / double(i);
      sum = sum + tmp;
   }
   cout << setprecision(10) << fixed << sum;
   return 0;
}
    