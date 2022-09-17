// MANG64

#include <iostream>
using namespace std;
int main()
{
   long long n;
   cin >> n;
   for (long long i = 0, tmp = 2; i < n; ++i)
   {
      for (long long j = 0; j < n; ++j)
         cout << j + tmp << ' ';
      cout << '\n';
      ++tmp;
   }
   return 0;
}
    