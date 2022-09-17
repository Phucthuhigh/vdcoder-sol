// MANG63

#include <iostream>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   for (long i = 0, sum; i < n; ++i)
   {
      sum = 0;
      for (long j = 0, tmp; j < n; ++j)
      {
         cin >> tmp;
         if (tmp % 2 == 0) sum += tmp;
      }
      cout << sum << '\n';
   }
   return 0;
}
    