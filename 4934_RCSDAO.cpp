// RCSDAO

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   for (long i = s.size() - 1; i > -1; --i)
      cout << s[i];
   return 0;
}
    