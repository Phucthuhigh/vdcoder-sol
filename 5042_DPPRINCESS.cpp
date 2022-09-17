// DPPRINCESS

#include <iostream>
#include <vector>

using namespace std;

vector<long long> a, f;
long t, n;

long long max(long long a, long long b) { if (a > b) return a; return b; }

void set_f()
{
   f.resize(n + 1);
   f[0] = 0;
   f[1] = a[1];
   for (long i = 2; i <= n; ++i)
      f[i] = max(a[i] + f[i - 2], f[i - 1]);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin >> t;
   for (long i = 0; i < t; ++i)
   {
      cin >> n;
      a.resize(n + 1);
      for (long i = 1; i <= n; ++i) cin >> a[i];
      set_f();
      cout << f[n] << '\n';
   }
   return 0;
}
    