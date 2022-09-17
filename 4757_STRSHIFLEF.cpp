// STRSHIFLEF

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s, tmp;
   cin >> s;
   tmp = s;
   if (s.size() == 1) 
   {
      if (s[0] == 'a') cout << 'z';
      else cout << --s[0];
   }
   else
   {
      long i = 0;
      while (i < s.size() && s[i] == 'a') ++i;
      while (i < s.size() && s[i] != 'a') --s[i++];
      if (s != tmp) cout << s;
      else
      {
         tmp[s.size() - 1] = 'z';
         cout << tmp;
      }
   }
   return 0;
}
    