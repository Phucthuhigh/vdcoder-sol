// STRKEYBOAR

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s, s1, s2;
   int a[26];
   cin >> s1 >> s2;
   for (long i = 0; i < s1.size(); ++i)
   {
      a[s1[i] - 'a'] = s2[i] - s1[i];
   }
   cin >> s;
   for (long i = 0, tmp; i < s.size(); ++i)
   {
      if (s[i] < 58) cout << s[i];
      else
      {
      	if (s[i] < 'a') tmp = 32;
      	else tmp = 0;
      	cout << char(s[i] + a[s[i] - 'a' + tmp]);
      }
   }
   return 0;
}
    