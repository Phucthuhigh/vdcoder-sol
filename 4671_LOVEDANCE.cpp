// LOVEDANCE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(long m, long n)
{
   vector<long> a, b;
   a.resize(m);
   b.resize(n);
   for (long i = 0; i < m; ++i) cin >> a[i];
   for (long i = 0; i < n; ++i) cin >> b[i];
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   for (long i = 0; i < m; ++i)
      if (a[i] <= b[i]) return 0;
   return 1;
}
int main()
{
   long m, n;
   cin >> m >> n;
   if (m > n) cout << "NO";
   else
   {
      if (check(m, n)) cout << "YES";
      else cout << "NO";
   }
   return 0;
}
    