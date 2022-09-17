// BRUBIENDOI

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   long long k;
   cin >> s >> k;
   while (k > 0 && s.size() > 0)
   {
      if (s.back() == '0') 
      { 
         s.pop_back();
         --k;
      }
      else
      {
         if (k >= s.back() - '0')
         {
            k = k - (s.back() - '0');
            s.back() = '0';
         }
         else 
         {
            s.back() -= k;
            k = 0;
         }
      }
   }
   if (s != "") cout << s;
   else cout << "0";
   return 0;
}
    