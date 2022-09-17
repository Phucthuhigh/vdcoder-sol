// STRPREFIX

#include <iostream>
using namespace std;
int main()
{
  long long n, dem = 0;
  string s;
  char a, b;
  cin >> n >> s;
  for (long i = 1; i < n; i += 2)
  {
     if (s[i] == s[i - 1])
     {
        ++dem;
        s[i] = 'b';
        s[i - 1] = 'a'; 
     }
  }
  cout << dem << '\n' << s;
  return 0;
}
    