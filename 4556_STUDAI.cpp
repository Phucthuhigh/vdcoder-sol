// STUDAI

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s, max = "";
   while (cin >> s)
   {
      if (s.size() > max.size()) max = s;
   }
   cout << max;
   return 0;
}
    