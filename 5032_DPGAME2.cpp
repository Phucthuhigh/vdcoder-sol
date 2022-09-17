// DPGAME2

#include <iostream>
#include <vector>

using namespace std;

vector<long long> f(100001, 0), a;

long long max(long long a, long long b) { if (a > b) return a; return b; }
int main()
{
   long n, k;
   cin >> n >> k;
   a.resize(n + 1);
   for (long i = 1, tmp; i <= n; ++i) cin >> a[i];
   
   f[0] = 0;
   for (long i = 1; i <= n; ++i)
   {
      long j = max(0, i - k);
      f[i] = a[i] + f[j++];
      for ( ; j < i ; ++j) f[i] = max(f[i], a[i] + f[j]);
   }
      
   long long max_ = 0;
   for (long i = 1; i <= n; ++i) max_ = max(max_, f[i]);
   cout << max_;
   return 0;
}
    