// RCSMAXNU

#include <iostream>
#include <string>
using namespace std;
int main()
{
   char res = 0;
   string s;
   cin >> s;
   for (long i = 0; i < s.size(); ++i) if (s[i] > res) res = s[i];
   cout << res;
   return 0;
}
    