// MANG66

#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long m, n;
   vector<long long> a;
   cin >> m >> n;
   a.resize(n);
   for (long i = 0; i < n; ++i) a[i] = 0;
   for (long i = 0; i < m; ++i) 
      for (long j = 0, tmp; j < n; ++j)
      {
         cin >> tmp;
         a[j] += tmp;
      }
   for (long i = 0; i < n; ++i) cout << a[i] << '\n';
   return 0;
}
    