// STRDAONG

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long n;
   string s;
   cin >> n >> s;
   for (long i = 1; i < s.size(); ++i)
      if (s[i - 1] > s[i]) { cout << "YES\n" << i << ' ' << i + 1; return 0; }
   cout << "NO";
   return 0;
}
    