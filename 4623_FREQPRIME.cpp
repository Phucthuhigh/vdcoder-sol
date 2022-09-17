// FREQPRIME

#include <iostream>
#include <string>
using namespace std;
bool prime(long long k)
{
   if (k == 2 || k == 3 || k == 5) return 1;
   if (k < 2 || k % 2 == 0 || k % 3 == 0 || k % 5 == 0) return 0;
   for (long long i = 5; i * i <= k; i += 6)
      if (k % i == 0 || k % (i + 2) == 0) return 0;
   return 1;
}
int main()
{
   string s;
   long long a[256], dem = 0;
   for (long i = 0; i < 256; ++i) a[i] = 0;
   getline(cin, s);
   for (long i = 0; i < s.size(); ++i) ++a[s[i]];
   for (long i = 0; i < 256; ++i)
   {
      if (prime(a[i])) dem += a[i];
   }
   cout << dem;
   return 0;
}
    