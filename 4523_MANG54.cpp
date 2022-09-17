// MANG54

#include <iostream>
using namespace std;
int main()
{
   long long n, max, res = 1;
   cin >> n;
   cin >> max;
   for (long long i = 2, tmp; i <= n; ++i)
   {
      cin >> tmp;
      if (tmp > max) {max = tmp; res = i; }
   }
   cout << max << ' ' << res;
   return 0;
}
    