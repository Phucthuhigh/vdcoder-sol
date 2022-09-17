// TLuythua

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
   long long a, b, c, d, al, bl, cl, dl;
   cin >> a >> b >> c >> d >>al >> bl >> cl >> dl;
   cout << pow(a, al) + pow(b, bl) + pow(c, cl) + pow(d, dl);
   return 0;
}
    