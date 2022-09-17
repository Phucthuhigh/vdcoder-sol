// SDAIHON

#include <iostream>
#include <string>
using namespace std;
void xuat(string s)
{
   for (long i = 0; i < s.size(); ++i)
      if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
   cout << s;
}
int main()
{
   string s1, s2;
   getline(cin, s1);
   getline(cin, s2);
   if (s1.size() > s2.size()) xuat(s1);
   else xuat(s2);
   return 0;
}
    