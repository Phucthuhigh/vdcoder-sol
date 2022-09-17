// STRDECODE

#include <iostream>
using namespace std;
int main()
{
  long long n;
  string s = "";
  char tmp;
  bool flag;
  cin >> n;
  if (n % 2 == 1) flag = false;
  else flag = true;
  for (long i = 0; i < n; ++i)
  {
     cin >> tmp;
     if (flag) s = tmp + s;
     else s = s + tmp;
     flag = !flag;
  }
  cout << s;
  return 0;
}
    