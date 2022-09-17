// SCHUANHOA

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   while (s.size() > 0 && s[0] == ' ') s.erase(s.begin());
   while (s.size() > 0 && s[s.size() - 1] == ' ') s.erase(s.end() - 1);
   for (long i = 0; i < s.size(); ++i)
   {
      if (s[i] == ' ')
      {
         ++i;
         while (i < s.size() && s[i] == ' ') s.erase(s.begin() + i);
      }
   }
   cout << s;
   return 0;
}
    