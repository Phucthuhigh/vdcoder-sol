// STRDECODE2

#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  cin >> s;
  if (s.size() % 2 == 0) s = ' ' + s;
  cout << s[s.size() / 2];
  for (long i = s.size() / 2 - 1; i > -1; --i)
  {
     cout << s[s.size() - 1 - i] << s[i];
  }
  return 0;
}
    