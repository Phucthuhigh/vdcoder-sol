// SXEDA

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long k;
   string s;
   cin >> k >> s;
   k = k % 26;
   for (long i = 0; i < s.size(); ++i)
   {
      s[i] = s[i] + k;
      if (s[i] > 'Z') s[i] -= 26;
   }
   cout << s;
   return 0;
}
    