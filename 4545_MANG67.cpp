// MANG67

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
   long long m, n;
   vector<long long> a;
   cin >> m >> n;
   a.resize(n);
   for (long i = 0; i < m; ++i) 
   {
      for (long j = 0; j < n; ++j) cin >> a[j];
      sort(a.begin(), a.end());
      for (long j = 0; j < n; ++j) cout << a[j] << ' ';
      cout << '\n';
   }
   return 0;
}
    