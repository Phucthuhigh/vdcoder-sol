// STRDECHAR

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
   string s, t, tmp;
   long i = 1;
   vector<long> a;
   cin >> s >> t;
   s = ' ' + s;
   t = ' ' + t;
   while (i < t.size() && s[i] == t[i]) ++i;
   
   tmp = s;
   tmp.erase(tmp.begin() + i);
   if (tmp != t) { cout << 0; return 0; }
   
   while (i > 0 && s[i] == s[i - 1]) --i;
   if (i == 0) ++i;
   char k = s[i];
   while (i < s.size() && s[i] == k) a.push_back(i++);
   cout << a.size() << '\n';
   for ( i = 0; i < a.size(); ++i) cout << a[i] << ' ';
   return 0;
}
    