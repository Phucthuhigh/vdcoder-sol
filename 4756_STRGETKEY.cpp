// STRGETKEY

#include <iostream>
using namespace std;
int main()
{
   long long n, dem = 0, a[26];
   char tmp1, tmp2;
   cin >> n;
   for (long i = 0; i < 26; ++i) a[i] = 0;
   for (long i = 1; i < n; ++i)
   {
      cin >> tmp1 >> tmp2;
      ++a[tmp1 - 'a'];
      tmp2 = tmp2 - 'A';
      if (a[tmp2] > 0) --a[tmp2];
      else ++dem;
   }
   cout << dem;
   return 0;
}
    