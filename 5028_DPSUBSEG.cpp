// DPSUBSEG

#include <iostream>
#include <vector>

using namespace std;

long long n, t;
vector<long long> f, a;

int main()
{
   ios_base::sync_with_stdio(false);
   cin >> t;
   for (long u = 0; u < t; ++u)
   {
      cin >> n;
      a.resize(n + 1);
      for (long i = 1; i <= n; ++i) cin >> a[i];
      
      f.resize(n + 1);
      f[n] = 1;
      for (long i = n - 1; i > 0; --i) 
         if (a[i] * a[i + 1] < 0) f[i] = f[i + 1] + 1;
         else f[i] = 1;
      
      for (long i = 1; i <= n; ++i) cout << f[i] << ' ';
      cout << '\n';
   }
   return 0;
}
    