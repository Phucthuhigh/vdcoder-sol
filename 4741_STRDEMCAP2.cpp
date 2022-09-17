// STRDEMCAP2

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
   string s;
   cin >> s;
   vector <long long> a(256, 0);
   long long dem = 0;
   for (long i = 0; i < s.size(); ++i) ++a[s[i]];
   for (long i = 0; i < 256; ++i) dem = dem + a[i] * (a[i] - 1) / 2;
   cout << dem;
   return 0;
}
    