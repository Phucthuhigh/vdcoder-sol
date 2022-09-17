// RCSSUM2

#include <iostream>
using namespace std;
int main()
{
   long long n, res;
   cin >> n;
   while (n > 9)
   {
      res = 0;
      while (n > 0)
      {
         res = res + n % 10;
         n /= 10;
      }
      n = res;
   }
   cout << n;
   return 0;
}
    