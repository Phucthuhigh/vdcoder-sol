// KHUMA

#include <iostream>
using namespace std;
int main()
{
   long long n, tmp;
   cin >> n;
   tmp = n;
   while (n > 9)
   {
      tmp = tmp + n / 10 * 3;
      n = n / 10 * 3 + n % 10;
   }
   cout << tmp;
   return 0;
}
    