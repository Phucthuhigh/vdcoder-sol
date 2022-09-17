// RCSLT1

#include <iostream>
using namespace std;
int main()
{
   long long n, x;
   cin >> n >> x;
   long long tmp = n, res = 1;
   while (x > 0)
   {
      if (x % 2 == 1) res *= tmp;
      tmp *= tmp;
      x /= 2;
   }
   cout << res;
   return 0;
}
    