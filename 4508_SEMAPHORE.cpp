// SEMAPHORE

#include <iostream>
#include <string>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   string s = "\n";
   for (long long i = 0; i < n; ++i)
      s = '*' + s;
   for (long long i = 0; i < n; ++i)
   {
      cout << s;
      s.erase(s.begin());
   }
   return 0;
}
    