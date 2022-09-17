// SDEMA

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long dem = 0;
   string s;
   getline(cin, s);
   for (long i = 0; i < s.size(); ++i)
      if (s[i] == 'A') ++dem;
   cout << dem;
   return 0;
}
    