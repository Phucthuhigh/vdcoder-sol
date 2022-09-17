// BTKBINA1

#include <iostream>
#include <string>
using namespace std;
long n;
void sinh(string &s)
{
   if (s.size() == n) cout << s << '\n';
   else
   {
      s = s + '0';
      sinh(s);
      s.pop_back();
      
      s = s + '1';
      sinh(s);
      s.pop_back();
   }
}
int main()
{
   cin >> n;
   string s = "";
   sinh(s);
   return 0;
}
    