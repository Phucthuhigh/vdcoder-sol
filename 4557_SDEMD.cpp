// SDEMD

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   long a[26];
   for (long i = 0; i < 26; ++i) a[i] = 0;
   cin >> s;
   for (long i = 0; i < s.size(); ++i) ++a[s[i] - 'A'];
   for (long i = 0; i < 26; ++i)
      if (a[i] > 0) cout << char(i + 'A') << ' ' << a[i] << '\n';
   return 0;
}
    