// DPTICK

#include <iostream>
#include <vector>

using namespace std;

vector<long long> t, r, f;
long n;

long long min(long long a, long long b) { if (a < b) return a; return b; }

void set_f()
{
   f.resize(n + 1);
   f[0] = 0;
   f[1] = t[1];
   for (long i = 2; i <= n; ++i)
      f[i] = min(t[i] + f[i - 1], r[i - 1] + f[i - 2]);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin >> n;
   
   t.resize(n + 1);
   r.resize(n);
   for (long i = 1, tmp; i <= n; ++i) cin >> t[i];
   for (long i = 1, tmp; i < n; ++i) cin >> r[i];
   
   set_f();
   cout << f[n];
   return 0;
}
    