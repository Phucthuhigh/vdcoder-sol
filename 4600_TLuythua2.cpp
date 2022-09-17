// TLuythua2

#include <iostream>
using namespace std;
long long pow(long long a, long long b)
{
   long long res = 1, tich = a;
   while (b > 0)
   {
      if (b % 2 == 1) res *= tich;
      tich *= tich;
      b /= 2;
   }
   return res;
}
int main()
{
   long long m, n, sum = 0;
   cin >> m >> n;
   for (long long i = 1; i <= m; ++i) sum += pow(i, n);
   cout << sum;
   return 0;
}
    