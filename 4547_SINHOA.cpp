// SINHOA

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   for (long i = 0; i < s.size(); ++i)
      if (s[i] > 96) cout << char(s[i] - 32);
      else cout << s[i];
   return 0;
}
    