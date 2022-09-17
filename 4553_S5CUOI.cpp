// S5CUOI

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   for (long i = s.size() - 5; i < s.size(); ++i) cout << s[i];
   return 0;
}
    