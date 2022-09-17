// CTC97

#include <iostream>
#include <string>
using namespace std;
bool comp(string s1, string s2)
{
   if (s1.size() > s2.size()) return 1;
   if (s1.size() < s2.size()) return 0;
   for (long i = 0; i < s1.size(); ++i)
   {
      if (s1[i] > s2[i]) return 1;
      if (s1[i] < s2[i]) return 0;
   }
   return 0;
}
int main()
{
   string s1, s2, s3, s4;
   cin >> s1 >> s2;
   s3 = s1;
   s4 = s2;
   while (s3.size() > 0 && s3[0] == '0') s3.erase(s3.begin());
   while (s4.size() > 0 && s4[0] == '0') s4.erase(s4.begin());
   if (comp(s3, s4)) cout << s1;
   else cout << s2;
   return 0;
}
    