// XoaEM

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long k = 0;
   string s;
   getline(cin, s);
   for (long long i = 0; i < s.size(); )
   {
      if (s[i] == 'm')
      {
         if (k > 0)
         {
            s.erase(s.begin() + i - 1, s.begin() + i + 1);
            --k;
            --i;
         }
         else 
         {
            k = 0;
            ++i;
         }
      }
      else
      {
         if (s[i] == 'e') ++k;
         else k = 0;
         ++i;
      }
   }
   cout << s;
   return 0;
}
    