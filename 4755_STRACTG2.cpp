// STRACTG2

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long n, a = 0, c = 0, g = 0, t = 0;
   string s;
   cin >> n >> s;
   for (long i = 0; i < n; ++i)
   {
      switch (s[i])
      {
         case 'A': ++a; break;
         case 'C': ++c; break;
         case 'G': ++g; break;
         case 'T': ++t; break;
      }
   }
   if (n % 4 == 0 && a <= n / 4 && c <= n / 4 && g <= n / 4 && t <= n / 4)
   {
      long i;
      for (i = 0; i < n && a < n / 4; ++i)
         if (s[i] == '?') { s[i] = 'A'; ++a; }
      for (; i < n && c < n / 4; ++i)
         if (s[i] == '?') { s[i] = 'C'; ++c; }
      for (; i < n && g < n / 4; ++i)
         if (s[i] == '?') { s[i] = 'G'; ++g; }
      for (; i < n && t < n / 4; ++i)
         if (s[i] == '?') { s[i] = 'T'; ++t; } 
      cout << s;
   }
   else cout << "NO";
   return 0;
}
    