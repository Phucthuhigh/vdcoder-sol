// GROVESTR

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   string s, ans = "";
   cin >> s;
   long n = s.size();
   sort(s.begin(), s.end());
   ans = ans + s[n - 1];
   for (long i = n - 2; i > -1; --i) 
   {
      if (i % 2 == 1) ans = ans + s[i];
      else ans = s[i] + ans;
   }
   cout << ans;
   return 0;
}
    