// MATRAN

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   cout << setprecision(2) << fixed;
   long long m, n;
   cin >> m >> n;
   for (long long i = 0; i < m; ++i)
   {
      double max = 0, tmp;
      for (long long j = 0; j < n; ++j)
      {
         cin >> tmp;
         if (max < tmp) max = tmp;
      }
      cout << max << '\n';
   }
   return 0;
}
    