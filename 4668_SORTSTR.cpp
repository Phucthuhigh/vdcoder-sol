// SORTSTR

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   long long n, i;
   string s, kq = "";
   cin >> s;
   sort(s.begin(), s.end());
   for (i = 0; i < s.size(); ++i)
   {
      if (s[i] <= 'Z') kq = s[i] + kq;
      else break;
   }
   cout << kq;
   kq = "";
   for (; i < s.size(); ++i)
   {
      kq = s[i] + kq;
   }
   cout << kq;
   return 0;
}
    