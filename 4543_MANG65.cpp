// MANG65

#include <iostream>
using namespace std;
int main()
{
   long long n, sum = 0, tmp;
   cin >> n;
   for (long i = 1; i < n; ++i)
   {
      cin >> tmp;
      sum += tmp;
      for (long j = 0; j < n; ++j)
         cin >> tmp;
   }
   cin >> tmp;
   cout << sum + tmp;
   return 0;
}
    