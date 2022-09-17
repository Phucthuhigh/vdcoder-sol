// BRUPALIN

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   cin >> s;
   long n = s.size(), dif = 0;
   for (long i = 0; i <= (n - 1) / 2; ++i) if (s[i] != s[n - i - 1]) ++dif;
   if ((n % 2 == 0 && dif == 1) || (n % 2 == 1 && dif < 2)) cout << "YES";
   else cout << "NO";
   return 0;
}
    