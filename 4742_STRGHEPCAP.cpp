// STRGHEPCAP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
   string s1, s2, s;
   cin >> s1 >> s2 >> s;
   s1 = s1 + s2;
   if (s1.size() >= s2.size())
   {
      vector <long long> a(256, 0), b(256, 0);
      for (long i = 0; i < s1.size(); ++i) ++a[s1[i]];
      for (long i = 0; i < s.size(); ++i) ++b[s[i]];
      for (long i = 0; i < 256; ++i) if (a[i] < b[i]) { cout << "NO"; return 0; }
      cout << "YES";
   }
   else cout << "NO";
   return 0;
}
    