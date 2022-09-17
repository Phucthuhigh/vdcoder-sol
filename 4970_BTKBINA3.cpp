// BTKBINA3

#include <iostream>
#include <string>
#include <vector>
using namespace std;
long n;
vector<string> a;
void sinh(string &s)
{
   if (s.size() == n) a.push_back(s);
   else
   {
      s = s + '0';
      sinh(s);
      s.pop_back();
      
      if (s.back() == '0')
      {
         s = s + '1';
         sinh(s);
         s.pop_back();
      }
   }
}
int main()
{
   cin >> n;
   string s = "0";
   sinh(s);
   s = "1";
   sinh(s);
   
   cout << a.size() << '\n';
   for (long i = 0; i < a.size(); ++i)
      cout << a[i] << '\n';
   return 0;
}
    