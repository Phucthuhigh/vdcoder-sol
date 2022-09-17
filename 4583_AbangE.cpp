// AbangE

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long k = 0;
   string s, stmp = "anh";
   getline(cin, s);
   for (long i = 0; i < s.size(); )
   {
      if (k == 3) 
      { 
         k = 0;
         s[i - 3] = 'e'; 
         s[i - 2] = 'm'; 
         s.erase(s.begin() + i - 1); 
         --i;
      }
      else
      {
         if (s[i] == stmp[k]) ++k;
         else 
         {
            if (s[i] == stmp[0]) k = 1;
            else k = 0;
         }
         ++i;
      }
   }
   if (k == 3) 
   {
      s[s.size() - 3] = 'e';
      s[s.size() - 2] = 'm';
      s.erase(s.end() - 1);
   }
   cout << s;
   return 0;
}
    