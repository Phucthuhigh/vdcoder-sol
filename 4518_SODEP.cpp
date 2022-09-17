// SODEP

#include <iostream>
using namespace std;
int main()
{
   long long n, tmp = 0;
   cin >> n;
   while (n > 0)
   {
      tmp = tmp + n % 10;
      n /= 10;
   }
   if (tmp % 10 == 9) cout << "YES";
   else cout << "NO";
   return 0;
}
    