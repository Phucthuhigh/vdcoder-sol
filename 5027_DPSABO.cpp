// DPSABO

#include <iostream>
#include <vector>

using namespace std;

long long n, k, mod = 1e6;
vector<long long> f;

long long sap_bo(long long m)
{
   if (m < 0) return 0;
   if (f[m] == -1) f[m] = ( sap_bo(m-1) + sap_bo(m - k - 1) ) % mod;
   return f[m];
}
int main()
{
   cin >> n >> k;
   if (k > n) k = n;
   f.resize(n + 1);
   for (long i = 0; i <= k; ) f[i] = ++i;
   for (long i = k + 1; i <= n; ++i) f[i] = -1;
   cout << sap_bo(n);
   return 0;
}
    