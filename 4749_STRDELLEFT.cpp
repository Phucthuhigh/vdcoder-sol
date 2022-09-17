// STRDELLEFT

#include <iostream>
#include <string>
using namespace std;
int main()
{
  long dem = 0, i;
  string s, t;
  cin >> s >> t;
  if (s.size() > t.size()) {dem = s.size() - t.size(); s.erase(s.begin(), s.begin() + dem); }
  if (s.size() < t.size()) {dem = t.size() - s.size(); t.erase(t.begin(), t.begin() + dem); }
  for (i = s.size() - 1; i > -1; --i) if (s[i] != t[i]) break;
  dem = dem + (i + 1) * 2;
  cout << dem;
  return 0;
}
    