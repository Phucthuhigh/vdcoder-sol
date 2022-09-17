// BTKBINA2

#include <iostream>
#include <string>
#include <vector>
using namespace std;
long n;
vector<string> a;
void sinh(string &s, bool flag)
{
   if (s.size() == n) a.push_back(s);
   else
   {
      s = s + '0';
      sinh(s, flag);
      s.pop_back();
      
      if (flag || s.back() != '0')
      {
         if (s.back() == '0')
         flag = false;
         s = s + '1';
         sinh(s, flag);
         s.pop_back();
      }
   }
}
int main()
{
   cin >> n;
   string s = "0";
   sinh(s, true);
   s = "1";
   sinh(s, true);
   
   cout << a.size() << '\n';
   for (long i = 0; i < a.size(); ++i)
      cout << a[i] << '\n';
   return 0;
}
    