// BRUDAYSO

#include <iostream>
using namespace std;
int main()
{
   long long n, dem = 1;
   cin >> n;
   while (n != 1)
   {
      if (n % 2 == 1) n = 3 * n + 1;
      else n /= 2;
      ++dem;
   }
   cout << dem;
   return 0;
}
    