// RCSOLD

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long dem = 0;
   string s;
   cin >> s;
   for (long i = 0; i < s.size(); ++i) if (s[i] % 2 == 1) ++dem;
   cout << dem;
   return 0;
}
    