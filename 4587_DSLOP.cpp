// DSLOP

#include <iostream>
#include <string>
using namespace std;
string chuanhoaxau(string s)
{
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
   return s;
}
int main()
{
   string s;
   while (getline(cin, s))
   {
      cout << chuanhoaxau(s) << '\n';
   }
   return 0;
}
    