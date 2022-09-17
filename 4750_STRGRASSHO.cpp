// STRGRASSHO

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long n, k, i;
   string s;
   bool flag = true;
   cin >> n >> k >> s;
   for (i = 0; i < n; ++i) if (s[i] == 'T' || s[i] == 'G') break;
   for (i += k; i < n; i += k) 
   {
      if (s[i] == 'T' || s[i] == 'G') break;
      if (s[i] == '#') { flag = false; break; }
   }
   if (flag && i < n) cout << "YES";
   else cout << "NO";
   return 0;
}
    