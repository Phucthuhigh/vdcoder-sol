// SBIEUTHUC

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   char k = '+';
   long long tmp_so, sum = 0;
   cin >> s;
   while (s.size() > 0)
   {
      tmp_so = 0;
      while(s.size() > 0 && s[0] >= '0' && s[0] <= '9') 
      {
         tmp_so = tmp_so * 10 + (s[0] - '0');
         s.erase(s.begin());
      }
      if (k == '+') sum += tmp_so;
      if (k == '-') sum -= tmp_so;
      if (s.size() > 0) 
      { 
         k = s[0];
         s.erase(s.begin());
      }
   }
   cout << sum;
   return 0;
}
    