// LOP

#include <iostream>
#include <string>
using namespace std;
string tachlayten(string s)
{
   string tmp = "";
   long i = s.size() - 1;
   while (i >= 0 && s[i] != ' ')
   {
      tmp = s[i] + tmp;
      --i;
   }
   return tmp;
}
int main()
{
   string s;
   while (getline(cin, s))
   {
      cout << tachlayten(s) << '\n';
   }
   return 0;
}
    