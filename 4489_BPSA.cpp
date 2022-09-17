// BPSA

#include <iostream>
using namespace std;
long long solve(long long x)
{
   if (x > 0)
      return x * x * x;
   else return x * x;
}
int main()
{
   long long m, n, k;
   cin >> m >> n >> k;
   cout << solve(m) << ' ' << solve(n) << ' ' << solve(k);
   return 0;
}
    