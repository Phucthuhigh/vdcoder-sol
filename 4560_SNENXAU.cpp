// SNENXAU

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   long tmp_so;
   char k;
   while (cin >> s)
   {
      if (s[0] >= '0' && s[0] <= '9')
      {
         for (long i = 0; i < s.size(); ++i)
         {
            tmp_so = 0;
            while(s[i] >= '0' && s[i] <= '9') 
            {
               tmp_so = tmp_so * 10 + (s[i] - '0');
               ++i;
            }
            k = s[i];
            for (long j = 0; j < tmp_so; ++j) cout << k;
         }
      }
      else
      {
         for (long i = 0; i < s.size(); )
         {
            k = s[i];
            tmp_so = 0;
            while (i < s.size() && s[i] == k) { ++tmp_so; ++i; }
            cout << tmp_so << k;
         }
      }
      cout << '\n';
   }
   return 0;
}
    