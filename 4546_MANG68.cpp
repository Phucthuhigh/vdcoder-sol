// MANG68

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   long long m, n;
   vector<long long> a;
   cin >> m >> n;
   a.resize(m * n);
   for (long i = 0; i < m * n; ++i) cin >> a[i];
   sort(a.begin(), a.end());
   for (long i = 0; i < m; ++i)
   {
      for (long j = 0; j < n; ++j) cout << a[i * n + j] << ' ';
      cout << '\n';
   }
   return 0;
}
    