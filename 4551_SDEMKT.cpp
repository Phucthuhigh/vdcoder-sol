// SDEMKT

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long dem = 0;
   string s;
   getline(cin, s);
   for (long i = 0; i < s.size(); ++i)
      if (s[i] >= '0' && s[i] <= '9') ++dem;
   cout << dem;
   return 0;
}
    