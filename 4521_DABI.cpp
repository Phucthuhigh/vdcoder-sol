// DABI

#include <iostream>
using namespace std;
long long tongchuso(long long n)
{
   long long tmp = 0;
   while (n > 0)
   {
      tmp = tmp + n % 10;
      n /= 10;
   }
   return tmp;
}
int main()
{
   long long n;
   cin >> n;
   if (n % tongchuso(n) == 0) cout << 1;
   else cout << 0;
   return 0;
}
    