// HOANHAO

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   long long n, sum = 1;
   cin >> n;
   for (long long i = 2; i <= n / 2; ++i)
   {
      if (n % i == 0) sum += i;
   }
   if (sum == n) cout << "YES";
      else cout << "NO";
   return 0;
}
    