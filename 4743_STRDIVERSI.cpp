// STRDIVERSI

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
long n;
bool check()
{
   for (long i = 1; i < s.size(); ++i) 
      if (s[i] - s[i - 1] != 1) return 0;
   return 1;
}
int main()
{
   cin >> n;
   for (long i = 0; i < n; ++i)
   {
      cin >> s;
      sort(s.begin(), s.end());
      if (check()) cout << "Yes\n";
      else cout << "No\n";
   }
   return 0;
}
    