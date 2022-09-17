// RCSEVEN

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long res = 0;
   string s;
   cin >> s;
   for (long i = 0; i < s.size(); ++i) if (s[i] % 2 == 0) 
      res = res + s[i] - '0';
   cout << res;
   return 0;
}
    