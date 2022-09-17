// STENCHUAN

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   while (cin >> s)
   {
      if (s[0] <= 'z' && s[0] >= 'a') s[0] -= 32;
      for (long i = 1; i < s.size(); ++i)
         if (s[i] <= 'Z' && s[i] >= 'A') s[i] += 32;
      cout << s << ' ';
   }
   return 0;
}
    