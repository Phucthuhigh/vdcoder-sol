// MANG62

#include <iostream>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   for (long i = 0, max; i < n; ++i)
   {
      max = 0;
      for (long j = 0, tmp; j < n; ++j)
      {
         cin >> tmp;
         if (tmp > max) max = tmp;
      }
      cout << max << '\n';
   }
   return 0;
}
    